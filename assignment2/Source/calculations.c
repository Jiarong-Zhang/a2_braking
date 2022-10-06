// a1793769 - Emily Zhang
/**
 * File name calculations.c
 * Description: Implementation for operations that perfrom the main
torque & braking distance calculations
**/

/********** Include required submodules**********/

#include "calculations.h"

/********** Function Definitions **********/

// v = Rw
float calculateVehicleLinVel(float wheel_ang_vel) {
  float result = ROLLING_RADIUS * wheel_ang_vel;
  return result;
}

// s = 0.36v + 0.1v^2
float calculateMinBrkDist(float vehicle_lin_vel) {
  float result =
      (0.36 * vehicle_lin_vel) + (0.1 * (vehicle_lin_vel * vehicle_lin_vel));
  return result;
}

float calculateRelativeVel(void) {
  float result = 0.5 * (g_dist_buffer[BUFFER_SIZE - 1] - g_dist_buffer[0]);

  return result;
}

float calculateBrakingTorque(float vehicle_lin_vel, float dist_to_obst) {
  float deceleration = 0;
  float wheel_ang_acc = 0;
  float est_brk_force = 0;
  float braking_torque = 0;

  // a = -(v^2)/(2d)
  deceleration = -(vehicle_lin_vel * vehicle_lin_vel) / (2 * dist_to_obst);

  // wheel_ang_acc = a/R
  wheel_ang_acc = deceleration / ROLLING_RADIUS;

  // ma = -F, F = -ma
  est_brk_force = -(deceleration * QTR_CAR_MASS);

  // T = F*R+J(wheel_ang_acc)
  braking_torque =
      (est_brk_force * ROLLING_RADIUS) + (MOMENT_OF_INERTIA * wheel_ang_acc);

  return braking_torque;
}

void calculationsHandler(void) {
  volatile float angular_velocity = 0;
  volatile float linear_velocity = 0;
  volatile float min_distance = 0;
  volatile float relative_velocity = 0;
  volatile float braking_torque = 0;

  // First, get vehicle linear velocity
  angular_velocity = encoderGetVelocity();
  linear_velocity = calculateVehicleLinVel(angular_velocity);

  // Then check minimum braking distance
  min_distance = calculateMinBrkDist(linear_velocity);

  // Also check relative velocity
  relative_velocity = calculateRelativeVel();

  // Calculate relative braking torque
  braking_torque = calculateBrakingTorque(linear_velocity, g_dist_buffer[1]);

  // Clear output to DAC
  dacReset();

  // Send warning? (distance)
  if ((min_distance > g_dist_buffer[1]) && (relative_velocity < 0)) {
    // send warning, do not write to DAC
    aebWarning();
  }
  // Send warning? (torque)
  else if ((braking_torque > MAX_BRAKE_TORQUE) && (relative_velocity < 0)) {
    // send warning,do not write to DAC
    aebWarning();
  } else if (braking_torque == 0x00) {
    dacWrite(0x01);
  } else if ((braking_torque > 0) && (braking_torque < MAX_BRAKE_TORQUE)) {
    dacWrite((unsigned int)braking_torque * DAC_SCALE_FACTOR);
  }
}