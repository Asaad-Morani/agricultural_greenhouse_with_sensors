#include "soil_sensor.h"


void soil_sensor(){

	uint16_t readValue;

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, 1);
	HAL_Delay(20);
	HAL_ADC_PollForConversion(&hadc1,1000);
	readValue = HAL_ADC_GetValue(&hadc1);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, 0);

	char buffer[20]; // Buffer to store the string representation of readValue

	// Convert integer to string
	snprintf(buffer, sizeof(buffer), "%d\r\n", readValue);

	// Send the data over UART
	HAL_UART_Transmit(&huart7, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

	if (readValue > 40){
		printf("%d\n\r", readValue);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, 0);
	}
	else if (readValue > 10 ){
		printf("%d\n\r", readValue);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, 0);
	}
	else{
		printf("%d\n\r", readValue);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, 1);
	}
	HAL_Delay(500);

}
