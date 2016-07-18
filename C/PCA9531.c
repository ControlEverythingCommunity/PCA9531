// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9531
// This code is designed to work with the PCA9531_I2CPWM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Open-Collectors?sku=PCA9531_I2CPWM#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, PCA95351 I2C address is 0x60(96)
	ioctl(file, I2C_SLAVE, 0x60);

	// Select frequency prescaler 0 register(0x01)
	// Period of blink = 0.5 sec(0x4B)
	char config[2] = {0};
	config[0] = 0x01;
	config[1] = 0x4B;
	write(file, config, 2);
	sleep(1);
	
	// Select pulse width modulation 0 register(0x02)
	// Duty cycle = 50%(0x80)
	config[0] = 0x02;
	config[1] = 0x80;
	write(file, config, 2);
	
	// Select LED selector register(0x05)
	// Output set to Blinking at PWM0(0xAA)
	config[0] = 0x05;
	config[1] = 0xAA;
	write(file, config, 2);
	
	// Select LED selector register1(0x06)
	// Output set to Blinking at PWM0(0xAA)
	config[0] = 0x06;
	config[1] = 0xAA;
	write(file, config, 2);
}
