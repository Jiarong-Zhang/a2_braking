// a1793769 - Emily Zhang
/**
Function declarations for operations that perfrom the main
torque & braking distance calculations 
**/
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <reg167.h>
#include "Drivers/aeb.h"
#include "Drivers/dac.h"
#include "encoder.h"
#include "lidar.h"


/********** Macros **********/

// Constant values used in our calculations
#define ROLLING_RADIUS 		0.484f		// R
#define QTR_CAR_MASS 		450			// m
#define MAX_BRAKE_TORQUE 	1000		// Tm
#define MOMENT_OF_INERTIA	0.685		// J

// Scale output to DAC
#define DAC_SCALE_FACTOR 	0.255f 		// 255/1000

/********** Function Declearations **********/

// Calculat vehicle linear velocity
// v = Rw
// 		Takes wheel angular velocity as argument
//		Returns vehicle linear velocity
float calculateVehicleLinVel(float wheel_ang_vel);

// Calculat minimum braking distance
// s = 0.36v + 0.1v^2
// 		Takes ehicle linear velocity as argument
//		Returns minimum braking distance
float calculateMinBrkDist(float vehicle_lin_vel);

// Calculat relative braking distance
// vr(tn) = 1/2f[d(tn+1) - d(tn-1)]
// 		Takes an array of distances between vehicle and 
//			obstruction as argument
//		Returns relative velocity
float calculateRelativeVel(float* buffer, unsigned int buffer_size);

// Calculat required braking torque
// T = F*R+J(alpha)
// 		Takes vehicle linear velocity, and distance to
// 			obstruction (at time n) as an argument
//		Returns minimum braking torque
float calculateBrakingTorque(float vehicle_lin_vel, float dist_to_obst);

// The main driver for our calculation functions
// 		Take no arguments
//		Returns nothing
void calculationsHandler(float* buffer);

#endif