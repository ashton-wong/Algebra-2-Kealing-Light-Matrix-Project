/*
  Lab 3C Photoresistor

  Challenge: add statements to read the sensor values on the Serial Monitor.  This will help you
  to set the appropriate values in the map statement.

*/

const int sensorPin = A0;
const int ledPin = 9;

int lightLevel;

void setup()
{
  // We'll set up the LED pin to be an output.
  // (We don't need to do anything special to use the analog input.)

  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600) goes here
}


void loop()
{
  lightLevel = analogRead(sensorPin); // Reads in a value from 0 to 1023 from the analog input

  /*Although the analogRead() function reads a value between 0 and 1023, the photoresistor may
    // hover between reading of 200 and 700 (depending on the ambient light
    // in the room).  We use the map() function to transform this range
    to a number between 0 and 255, which is a range that works well for this application.
  */


  lightLevel = map(lightLevel, 200, 700, 0, 255);

  // It is possible for map to return a value outside of our desired range. The constrain() function
  // will make sure that the number is within the range of 0 to 255.

  lightLevel = constrain(lightLevel, 0, 255);

  //Serial.println(lightLevel) goes here if you want to see the actual values

  // If the light level is under a set threshold, turn on the LED as a night light
  if (lightLevel < 100)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
