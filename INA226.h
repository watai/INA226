/*
This is a arduino library for the INA226 I2C Digital Power Meter Module.
The Sensor uses I2C for communication. 2 pins are required to
interface to the device.

Reference:
http://strawberry-linux.com/catalog/items?code=12031
Datasheet:
http://www.ti.com/lit/ds/sbos547/sbos547.pdf

Created by Taiki Watai, Fab 2014.
*/

#ifndef INA226_H
#define INA226_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Wire.h>

// INA226 Registers
#define INA226_CONFIG 	0x00 // Configuration Register (R/W)
#define INA226_SHUNTV 	0x01 // Shunt Voltage (R)
#define INA226_BUSV   	0x02 // Bus Voltage (R)
#define INA226_POWER  	0x03 // Power (R)
#define INA226_CURRENT	0x04 // Current (R)
#define INA226_CALIB  	0x05 // Calibration (R/W)
#define INA226_MASK   	0x06 // Mask/Enable (R/W)
#define INA226_ALERTL 	0x07 // Alert Limit (R/W)
#define INA226_DIE_ID 	0xff // Die ID (R)
  
// Operating Mode (Mode Settings[0-2])
#define INA226_MODE_POWER_DOWN 			(0<<0) // Power-Down
#define INA226_MODE_TRIG_SHUNT_VOLTAGE	(1<<0) // Shunt Voltage, Triggered
#define INA226_MODE_TRIG_BUS_VOLTAGE	(2<<0) // Bus Voltage, Triggered
#define INA226_MODE_TRIG_SHUNT_AND_BUS	(3<<0) // Shunt and Bus, Triggered
#define INA226_MODE_POWER_DOWN2			(4<<0) // Power-Down
#define INA226_MODE_CONT_SHUNT_VOLTAGE	(5<<0) // Shunt Voltage, Continuous
#define INA226_MODE_CONT_BUS_VOLTAGE	(6<<0) // Bus Voltage, Continuous
#define INA226_MODE_CONT_SHUNT_AND_BUS	(7<<0) // Shunt and Bus, Continuous (default) *

// Shunt Voltage Conversion Time (VSH CT Bit Settings[3-5])
#define INA226_VSH_140uS				(0<<3) // 140us
#define INA226_VSH_204uS                (1<<3) // 204us
#define INA226_VSH_332uS                (2<<3) // 332us
#define INA226_VSH_588uS                (3<<3) // 588us
#define INA226_VSH_1100uS               (4<<3) // 1.1ms (default)
#define INA226_VSH_2116uS               (5<<3) // 2.116ms
#define INA226_VSH_4156uS               (6<<3) // 4.156ms
#define INA226_VSH_8244uS               (7<<3) // 8.244ms *

// Bus Voltage Conversion Time (VBUS CT Bit Settings[6-8])
#define INA226_VBUS_140uS          		(0<<6) // 140us
#define INA226_VBUS_204uS          		(1<<6) // 204us
#define INA226_VBUS_332uS          		(2<<6) // 332us
#define INA226_VBUS_588uS          		(3<<6) // 588us
#define INA226_VBUS_1100uS         		(4<<6) // 1.1ms (default)
#define INA226_VBUS_2116uS         		(5<<6) // 2.116ms
#define INA226_VBUS_4156uS         		(6<<6) // 4.156ms
#define INA226_VBUS_8244uS         		(7<<6) // 8.244ms *

// Averaging Mode (AVG Bit Settings[9-11])
#define INA226_AVG_1               		(0<<9) // 1 (default)
#define INA226_AVG_4         			(1<<9) // 4
#define INA226_AVG_16              		(2<<9) // 16 *
#define INA226_AVG_64              		(3<<9) // 64
#define INA226_AVG_128             		(4<<9) // 128
#define INA226_AVG_256             		(5<<9) // 256
#define INA226_AVG_512             		(6<<9) // 512
#define INA226_AVG_1024            		(7<<9) // 1024

// Reset Bit (RST bit [15])
#define INA226_RESET_ACTIVE             (1<<15) //
#define INA226_RESET_INACTIVE           (0<<15) // *

#define INA226_CALIB_VAL 0x0A00 // 2mOhm = 0A00h

class INA226
{
  public:
  	void setAddr(int _addr);
  	void setup(void);
 	short read(byte reg);
  private:
  	// const static unsigned int INA226_CALIB_VAL = 0x0A00; // 2mOhm = 0A00
	int addr; // B1000000:0x40 || B1000001:0x41
  protected:
  	void write(byte reg, unsigned int val);
};

#endif
