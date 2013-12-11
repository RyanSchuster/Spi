/*

Arduino SPI library

See LICENSE.txt

*/

#include "Spi.h"


Spi::Spi()
{
}


void Spi::on()
{
	byte bin;

	/* flush */
	SPCR = 0x53;
	bin = SPSR;
	bin = SPDR;

	/* set pin modes */
	pinMode(PIN_MOSI, OUTPUT);
	pinMode(PIN_MISO, INPUT);
	pinMode(PIN_SCK, OUTPUT);

	/* put clock in idle state and let settle */
	/* fix this to be the clock idle state based on mode */
	digitalWrite(PIN_SCK, LOW);
	delay(50);
}


void Spi::off()
{
	/* disable all pins */
	pinMode(PIN_MOSI, INPUT);
	pinMode(PIN_MISO, INPUT);
	pinMode(PIN_SCK, INPUT);
}


byte Spi::transfer(byte outByte)
{
	byte inByte;

	SPDR = outByte;
	wait();
	return SPDR;
}


void Spi::setMode(byte mode)
{
	SPCR = mode;
}


byte Spi::getStatus()
{
	return SPSR;
}

void Spi::wait()
{
	do
	{
	} while (!(SPSR & (1 << SPIF)));
}