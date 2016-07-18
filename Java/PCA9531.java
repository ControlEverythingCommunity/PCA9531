// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9531
// This code is designed to work with the PCA9531_I2CPWM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Open-Collectors?sku=PCA9531_I2CPWM#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class PCA9531
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, PCA9531 I2C address is 0x60
		I2CDevice device = Bus.getDevice(0x60);
		
		// Select frequency prescaler 0 register
		// Period of blink = 0.5 sec
		device.write(0x01, (byte)0x4B);

		// Select pulse width modulation 0 register
		// Duty cycle = 50%
		device.write(0x02, (byte)0x80);

		// Select LED selector register 0
		// Output set to Blinking at PWM0
		device.write(0x05, (byte)0xAA);

		// Select LED selector register 1
		// Output set to Blinking at PWM0
		device.write(0x06, (byte)0xAA);
	}
}
