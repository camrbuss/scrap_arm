
// Copyright 2017 Victor Tango AutoDrive
// @Authors - Cam Buss (camrbuss)

#ifndef PILOT_CONTROLLER_H
#define PILOT_CONTROLLER_H

#include <dynamic_reconfigure/server.h>
#include <iostream>
#include "ros/ros.h"
#include <ros/time.h>
#include <stdio.h>

class Controller
{
public:
  /*!
    \param a an integer argument.
    \param s a constant character pointer.
    \return The computed pid level of the desired control output
  */
  void computePID(float setpoint, float reading);

  /*!
    \param p The proportional gain.
    \param i The integral gain.
    \param d a The derivative gain.
  */
  void updateGains(float p, float i, float d, float cutoff, float wind_lim);

  bool paused;  // Variable that can pause the integral
  float P, I, D;

  Controller();


private:
  float Kp, Ki, Kd; /*!< The pid constants, unitless */

  float windup_limit; /*!< Limit for integral windup, Units: TBD */
  float upper_limit; /*!< Saturation limit of hardware, Units: output units */
  float lower_limit; /*!< Saturation limit of hardware, Units: output units */
  float cutoff_frequency; /*!< PID derivate lowpass freq in radians/sec */

  float err;
  float prev_err;
  float prev_d;

  float w; /*!< cutoff frequency, Units: rad/s */
  float A; /*!< Constant for filter */
  float B; /*!< Constant for filter */
};

#endif  // PILOT_CONTROLLER_H
