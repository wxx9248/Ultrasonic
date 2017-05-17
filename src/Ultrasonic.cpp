#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(const uint8_t TrigPin, const uint8_t EchoPin)
{
	trigPin = TrigPin;
	echoPin = EchoPin;

	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

double Ultrasonic::getDistance(const uint8_t mmu)
{
	double val = 0.0;
	switch (mmu)
	{
	case CM:
		val = pulseIn() * velocity;
		break;
	case IN:
		val = pulseIn() * velocity * CM2IN;
		break;
	default:
		break;
	}

	if (val < LOBOUND || val > UPBOUND)
	{
		val = 0.0;
		isOutOfRange = true;
	}
	else
		isOutOfRange = false;

	return val;
}

uint16_t Ultrasonic::pulseIn()
{
	writeTrig(LOW);
	delayMicroseconds(2);				// Low level - 2¦Ìs
	writeTrig(HIGH);
	delayMicroseconds(10);				// High level - At least 10¦Ìs
	writeTrig(LOW);
	return (::pulseIn(echoPin, HIGH));
}

void Ultrasonic::writeTrig(const uint8_t mode)
{
	digitalWrite(trigPin, mode);
}

uint8_t Ultrasonic::readEcho()
{
	return (digitalRead(echoPin));
}
