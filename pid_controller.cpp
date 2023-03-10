/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  kpi_ = Kpi;
  kii_ = Kii;
  kdi_ = Kdi;
  output_lim_maxi_ = output_lim_maxi;
  output_lim_mini_ = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  cte_p_ = cte;
  // Skip usage of dt_ if it is invalid.
 if (dt_ > 0.001) {
   cte_d_ = (cte - cte_prev_) / dt_;
   cte_i_ += cte * dt_;
 }
  cte_prev_ = cte;
  error_ = kpi_ * cte_p_ + kii_ * cte_i_ + kdi_ * cte_d_;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = error_;
    total_error_ += pow(error_, 2);

    if (control > output_lim_maxi_) control = output_lim_maxi_;
    if (control < output_lim_mini_) control = output_lim_mini_;
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  dt_ = new_delta_time;
  return dt_;
}