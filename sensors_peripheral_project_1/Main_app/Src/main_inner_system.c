/**
 * @file main_Inner_System.c
 * @brief This file contains implementations for the main Inner System functionality.
 */

#include "main_inner_system.h"
#include "soil_sensor.h"
#include "ultra_sonic_sensor.h"
#include "micro_servo_motor.h"


void main_inner_system(){

	uint32_t dis= 0;
	char strCopy[15];

	soil_sensor();
	dis = ultra_sonic_sensor();

	motor_rotation();

	SSD1306_GotoXY (0, 0);
	SSD1306_Puts ("Distance:", &Font_11x18, 1);
	sprintf(strCopy,"%lu    ", dis);
	SSD1306_GotoXY (0, 30);
	SSD1306_Puts (strCopy, &Font_16x26, 1);
	SSD1306_UpdateScreen();
	HAL_Delay(50);

}
