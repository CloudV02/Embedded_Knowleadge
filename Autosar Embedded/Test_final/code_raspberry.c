#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

// ---------- Cấu hình ----------      // Kiểm tra đúng i2c bus
#define UART_DEVICE "/dev/serial0"

int main() {
    // ----- Mở I2C -----
    int addr = 0x08;
    const char *bus = "/dev/i2c-1";
    int i2c_fd = open(bus, O_RDWR);
    if (i2c_fd < 0) {
        perror("I2C open");
        return 1;
    }

    if (ioctl(i2c_fd, I2C_SLAVE, addr) < 0) {
        perror("I2C ioctl");
        close(i2c_fd);
        return 1;
    }

    // ----- Mở UART -----
    int uart_fd = open(UART_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK );
    if (uart_fd == -1) {
        perror("UART open");
        close(i2c_fd);
        return 1;
    }

    struct termios options;
    tcgetattr(uart_fd, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 10;  // 1.0 giây timeout

    tcflush(uart_fd, TCIFLUSH);
    tcsetattr(uart_fd, TCSANOW, &options);

    // ----- Vòng lặp chính -----
    uint8_t i2c_data = 1;
    uint8_t uart_data = 0;
 while (1) {
        // Gửi 1 byte qua I2C
        if (write(i2c_fd, &i2c_data, 1) != 1) {
            perror("I2C write");
        } else {
            printf("[I2C] Sent: %d\n", i2c_data);
      }
        sleep(1);
        // Chờ STM32 phản hồi qua UART
     if (read(uart_fd, &uart_data, 1) == 1) {
            printf("[UART] Received: %d\n", uart_data);
			i2c_data += 3;  // Tăng dữ liệu mỗi lần gửi
			if (i2c_data > 100) i2c_data = 1;
        } else {
            perror("UART read");
            write(i2c_fd, &i2c_data,1);
        }
        sleep(3);
    }
    close(i2c_fd);
    close(uart_fd);
    return 0;
}