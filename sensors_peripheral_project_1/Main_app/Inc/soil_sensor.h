#ifndef INC_SOIL_SENSOR_H_
#define INC_SOIL_SENSOR_H_

#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern uint16_t readValue;

extern UART_HandleTypeDef huart7; /**< UART handle for UART 7 interface */
#define UART_7 &huart7 /**< UART 7 handle */


void soil_sensor();


#endif /* INC_SOIL_SENSOR_H_ */
