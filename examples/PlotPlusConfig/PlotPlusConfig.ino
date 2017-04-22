#include <SoftwareSerial.h>

SoftwareSerial Soft(10, 11);

// the following define replaces the default output stream (Serial)
// with the provided SoftwareSerial instance
#define PLOT_PLUS_STREAM Soft

// uncomment the following to completely disable the plot statements
//#define PLOT_PLUS false


#include <PlotPlus.h>

void setup() {
	Soft.begin(9600);
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
