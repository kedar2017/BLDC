//_____  I N C L U D E S ___________________________________________________

#ifndef _CONFIG_MOTOR_H_
#define _CONFIG_MOTOR_H_

//! @brief  This enumeration contains the 6 differents values for the Hall Sensors
//! See design document. \n In this application, just 3 hall sensor are used

typedef  enum {HS_001=1,HS_010=2,HS_011=3,HS_100=4,HS_101=5,HS_110=6} Hall_Position; //! Hall Sensor : position 1 to 6
		 enum {RUN = TRUE, STOP = FALSE}; //! @brief  Define the two states of the motor
		 enum {CCW = TRUE, CW = FALSE}; //! @brief  Define Direction of rotor : CCW (counter clock wise) and CW (clock wise)

				// Define type of speed measure and number of samples
				//#define AVERAGE_SPEED_MEASUREMENT
#define N_SAMPLE  8
		enum {OPEN_LOOP  = 0, SPEED_LOOP = 1, CURRENT_LOOP = 2}; //! @brief  Regulation loop modes

// Here you have to define your control coefficients

#define Kp_speed 30 //! @brief  Speed regulation Proportional coefficient
#define Ki_speed 30 //! @brief  Speed regulation Integral coefficient
#define Kd_speed 0 //! @brief  Speed regulation Derivative coefficient

#define Kp_cur 1 //! @brief  Current regulation Proportional coefficient
#define Ki_cur 3 //! @brief  Current regulation Integral coefficient
#define Kd_cur 0 //! @brief  Current regulation Derivative coefficient

// All PID coef are multiplied by 2^Kmul
// For exemple : kp = 1 => Kp = 1 * 2^K_scal = 1 * 2^4 = 16
// To get the right result you have to divide the number by 2^K_scal
// So execute a K_scal right shift
//! @brief  Speed regulation scale factor
#define K_speed_scal 4
//! @brief  Current regulation scale factor
#define K_cur_scal 4

// Speed measurement
// K_SPEED = (60 * 255)/(n * t_timer0 * speed_max(rpm))
// with n : number of pairs of poles.
// and t_timer0 : 16us
#define K_SPEED 34152 // max speed : 7000 (MC100 motor)
//#define K_SPEED 11250 // max speed : 17000 (MMT 35-1LS motor)
// if you want to calculate the absolute speed
//   absolute_speed = alpha * measured_speed
//   with alpha = 60 / (n * K_SPEED * t_timer0)

#endif

/* IMAX for DAC is calculated on that way :
   Rshunt = 0.05 Ohm
   Vref = 2.56V
   DAC is left adjust so it is like a 8 bit DAC
   IMAX = imax(amp) * 0.05 * 5 * 256 / 2.56 + 128
   IMAX = imax * 25 + 128
   The result must be less than 254              */

//#define IMAX (4 * 25 + 128) /* 4 amps */
#define IMAX 228 