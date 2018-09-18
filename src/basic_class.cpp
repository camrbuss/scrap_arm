// @Authors - Cam Buss (camrbuss)

#include <scrap_arm/basic_class.h>

Controller::Controller()
{
  this->windup_limit = 1000;
  this->upper_limit = 1;
  this->lower_limit = 0;
  this->cutoff_frequency = 10;  // Units: Hz
  this->prev_err = 0.0f;
  this->prev_d = 0;
  this->P = 0.0f;
  this->I = 0.0f;
  this->D = 0.0f;

  this->paused = false;
}

void Controller::computePID(float setpoint, float reading)
{

}

void Controller::updateGains(float p, float i, float d, float cutoff, float wind_lim)
{
  this->Kp = p;
  this->Ki = i;
  this->Kd = d;

}
