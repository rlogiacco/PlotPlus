#include <PlotPlus.h>

void setup() {
	Serial.begin(9600);
}

void loop() {
	delay(500);
	// plot the first 3 analog pins
	plot(analogRead(A0), analogRead(A1), analogRead(A2));


	delay(500);
	int temperature = rand();
	int humidity = rand();
	// now plotting also temperature and humidity, you should maintain the same order
	plot(analogRead(A0), analogRead(A1), analogRead(A2), temperature, humidity);
}
