#include <Ultrasonic.h>

#define TRIG  12
#define ECHO  13

Ultrasonic SR04(TRIG, ECHO);

void setup()
{
  Serial.begin(115200);
  Serial.println("Distance measuring start.");
}

void loop()
{
  Serial.print(SR04.getDistance(CM));
  Serial.print("cm    ");
  Serial.print(SR04.getDistance(IN));
  Serial.println("in");
  delay(500);
}

