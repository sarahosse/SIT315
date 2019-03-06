/*
	SENSOR LIGHT
    Written by: Sarah Osse
    
  	This sketch is of a basic sensor light.
  	It does the following:
  
  		- receives input from the PIR motion sensor every 1 second
  		- if motion is detected, the LED is turned on for 5 seconds
  		- if motion is not detected, no action is taken
  
  	The motion status (detected/not detected)
  	and the LED/sensor light activation (activated/disactivated)
  	are printed to the Serial Monitor.

*/

const int LED = 9;
const int PIR = 6;

void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(PIR, INPUT);
  	Serial.begin(9600);
}

void loop()
{
  	// read the input value from motion sensor
	int value= digitalRead(PIR);
	
  	// determine whether any motion detected
  	// if motion DETECTED:
	if (value == HIGH)
	{
      	// turn the LED on
		digitalWrite(LED, HIGH);
      	// print to serial monitor
      	Serial.println("Motion has been detected, sensor light activated.");
      	// wait 5 seconds
		delay(5000);
      	// turn LED off
		digitalWrite(LED, LOW);
      	// print to serial monitor
      	Serial.println("Sensor light off.");
	}
  
  	// if motion NOT DETECTED
	else
	{
      	// keep LED off
		digitalWrite(LED, LOW);
      	// print to serial monitor
      	Serial.println("No motion detected.");
	}
  	  
  // detect motion every 1 second
  delay(1000);
}