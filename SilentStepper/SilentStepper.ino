#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1, 9, 8);


 char buf[50];


long lastMeasuredPosition = 0;

void setup()
{  

	int speed = 1000;
  
	stepper.setMaxSpeed(speed);
	stepper.setAcceleration(speed);
	Serial.begin(9600);

}

void loop()
{
  lastMeasuredPosition = stepper.currentPosition();
  
	stepper.move(1);
	stepper.run();
  
	delay(200);

  sprintf(buf, "position: %lu", lastMeasuredPosition); 
  Serial.println( buf );
}





