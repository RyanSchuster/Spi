/*

Arduino SPI library header

See LICENSE.txt

*/

#ifndef __SPI_H__
#define __SPI_H__


/*

TODO:
-flip enable bit of SPCR and get rid of hard-coded value
-setters (and getters?) for individual link properties
-Spi.off() needs to disable spi in SPCR
-#define SPCR and SPSR bits

*/


#include "Arduino.h"


#define PIN_SS		10
#define PIN_MOSI	11
#define PIN_MISO	12
#define PIN_SCK		13


class Spi
{
	public:

	Spi();

	void on();
	void off();
	byte transfer(byte inByte);

	void setMode(byte mode);

	byte getStatus();


	private:

	void wait();
};


#endif /*__SPI_H__*/