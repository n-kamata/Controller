/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
    double cte_p_ = 0.0;
    double cte_prev_ = 0.0;
    double cte_d_ = 0.0;
    double cte_i_ = 0.0;
    double error_ = 0.0;
  
    /*
    * Coefficients
    */
    double kpi_ = 0.0;
    double kii_ = 0.0;
    double kdi_ = 0.0;

    /*
    * Output limits
    */
    double output_lim_maxi_ = 0.0;
    double output_lim_mini_ = 0.0;
  
  
    /*
    * Delta time
    */
    double dt_ = 0.0;
  
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


