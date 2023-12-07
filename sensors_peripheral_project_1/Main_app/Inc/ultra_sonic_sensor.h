#ifndef INC_ULTRA_SONIC_SENSOR_H_
#define INC_ULTRA_SONIC_SENSOR_H_

#include "main.h"

extern TIM_HandleTypeDef htim1;

uint32_t ultra_sonic_sensor();

#define TRIG_PIN GPIO_PIN_12
#define TRIG_PORT GPIOF
#define ECHO_PIN GPIO_PIN_15
#define ECHO_PORT GPIOD


#endif /* INC_ULTRA_SONIC_SENSOR_H_ */
