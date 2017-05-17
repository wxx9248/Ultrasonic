#pragma once

#include <Arduino.h>
#include <inttypes.h>

#define VSOUND			346

#define CM				0
#define IN				1
#define CENTIMETER		CM			// Alternative spelling
#define INCH			IN
#define CM2IN			0.3937008

#define UPBOUND			200.0
#define LOBOUND			3.0

class Ultrasonic
{
	private:
		uint8_t trigPin, echoPin;
		const double velocity = (double) VSOUND * 100.0 / 1000000.0 / 2.0;
	
	public:
		Ultrasonic(const uint8_t, const uint8_t);
		double getDistance(const uint8_t);
		uint16_t pulseIn();
		void writeTrig(const uint8_t);
		uint8_t readEcho();
		bool isOutOfRange = false;
};

