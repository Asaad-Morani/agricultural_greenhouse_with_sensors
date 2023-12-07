/**
 * @file Tools.c
 * @brief This file contains implementations for printf and scanf functions
 *        using UART for debugging and communication.
 */

#include "tools.h"

/**
 * @brief Custom implementation of character output for printf.
 *
 * This function transmits a character through the UART_DEBUG interface
 * to provide a custom implementation of character output for printf.
 *
 * @param ch The character to be transmitted.
 * @return The transmitted character.
 */
int __io_putchar(int ch) {
	HAL_UART_Transmit(UART_DEBUG, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

/**
 * @brief Custom implementation of writing data for printf.
 *
 * This function transmits a specified number of characters through the UART_DEBUG
 * interface to provide a custom implementation of writing data for printf.
 *
 * @param file Unused file descriptor.
 * @param ptr Pointer to the data to be transmitted.
 * @param len Number of bytes to transmit.
 * @return The number of bytes transmitted.
 */
int _write(int file, char *ptr, int len) {
	HAL_UART_Transmit(UART_DEBUG, (uint8_t*) ptr, len, 0xFFFF);
	return len;
}

/**
 * @brief Custom implementation of character input for scanf.
 *
 * This function receives a character through the UART_DEBUG interface
 * to provide a custom implementation of character input for scanf.
 *
 * @return The received character.
 */
int __io_getchar(void) {
	uint8_t ch = 0;
	HAL_UART_Receive(UART_DEBUG, &ch, 1, HAL_MAX_DELAY);
	HAL_UART_Transmit(UART_DEBUG, &ch, 1, HAL_MAX_DELAY);
	return ch;
}

/**
 * @brief Custom implementation of reading data for scanf.
 *
 * This function receives characters through the UART_DEBUG interface and stores
 * them in a buffer until a carriage return or line feed character is encountered.
 *
 * @param file Unused file descriptor.
 * @param ptr Pointer to the buffer where the data will be stored.
 * @param len Maximum number of bytes to read.
 * @return The number of bytes read.
 */
int _read(int file, char *ptr, int len) {
	int DataIdx = 0;
	char ch;

	for (; DataIdx < len; DataIdx++) {
		ch = __io_getchar();
		*ptr = ch;
		ptr++;
		if (ch == CARRIAGE_RETURN || ch == LINE_FEED) {
			*(ptr) = 0;
			break;
		}
	}
	return DataIdx + 1;
}
