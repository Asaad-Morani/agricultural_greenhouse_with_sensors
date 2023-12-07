#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    // Open the UART device file
    int uart_fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);

    if (uart_fd == -1) {
        std::cerr << "Unable to open UART" << std::endl;
        return -1;
    }

    // Configure UART
    struct termios options;
    tcgetattr(uart_fd, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR | ICRNL;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart_fd, TCIFLUSH);
    tcsetattr(uart_fd, TCSANOW, &options);

    // Read from UART and print to stdout
    char buffer[256];
    while (true) {
        int bytesRead = read(uart_fd, &buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << buffer;
        }
    }

    // Close the UART file descriptor
    close(uart_fd);
    return 0;
}