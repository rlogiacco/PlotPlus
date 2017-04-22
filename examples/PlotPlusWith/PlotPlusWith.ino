#include <SoftwareSerial.h>
#include <PlotPlus.h>

SoftwareSerial Soft(10, 11);

void setup() {
	Serial.begin(9600);
    Soft.begin(600);
}

void loop() {
	delay(500);
	// plot the first 3 analog pins on the hardware serial
	plot(analogRead(A0), analogRead(A1), analogRead(A2));
	// the above is equivalent to plotWith(Serial, analogRead(A0), analogRead(A1), analogRead(A2));


	delay(500);
	int temperature = rand();
	int humidity = rand();
	// now plotting temperature and humidity, but on the software serial output stream
	plotWith(Soft, temperature, humidity);
}
