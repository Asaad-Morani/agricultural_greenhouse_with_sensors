#include "micro_servo_motor.h"

/*void servo_rotate(uint16_t angle) {
    // Map the angle (0 to 180) to the corresponding CCR value
    uint32_t pulse_width = 1000 + (angle * 1000) / 180;

    // Set the CCR value to control the servo position
    htim3.Instance->CCR2 = pulse_width;
    HAL_Delay(50);  // Wait for the servo to reach the desired position
}*/

void motor_rotation(){

/*	// Rotate from 0 to 180 degrees
	for (uint16_t angle = 0; angle <= 180; angle += 10) {
		servo_rotate(angle);
	}

	// Rotate back to 0 degrees
	for (uint16_t angle = 180; angle >= 0; angle -= 10) {
		servo_rotate(angle);
	}*/

	htim3.Instance->CCR2 = 75;  // duty cycle is .5 ms
	HAL_Delay(2000);
	htim3.Instance->CCR2 = 175;  // duty cycle is 2.5 ms
	HAL_Delay(2000);

	// If the timer's period is 1000, setting CCR2 to 175 would mean a duty cycle of (175/1000) × 100% = 17.5%

}
