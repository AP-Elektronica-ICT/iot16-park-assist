
 // this constant won't change.
 //It's the pin number 
 // of the sensor's output: 
 const int pingPin = 7;
 const int pingPin2 = 8;
 const int pingPin3 = 9;
 void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
 }
 
void loop() {
  // establish variables for duration of the ping,   
  // and the distance result in inches and centimeters:
  long duration,duration2, duration3, cm,cm2,cm3;

   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
   //set pinModes
   /*
   pinMode(pingPin, OUTPUT);
   pinMode(pingPin2, OUTPUT);
   pinMode(pingPin3, OUTPUT);
   //give a short LOW pulse to all pins
   digitalWrite(pingPin, LOW);
   digitalWrite(pingPin2,LOW);
   digitalWrite(pingPin3,LOW);
   //wait for 2 microseconds
   delayMicroseconds(2);
   //give HIGH pulse to all pins
   digitalWrite(pingPin, HIGH);
   digitalWrite(pingPin2,HIGH);
   digitalWrite(pingPin3,HIGH);
   //Delay
   delayMicroseconds(5);
   //set pins back to LOW
   digitalWrite(pingPin, LOW);
   digitalWrite(pingPin2,LOW);
   digitalWrite(pingPin3,LOW);
   */
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin,LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin,HIGH);
   delayMicroseconds(5);
   digitalWrite(pingPin,LOW);
  /*same pin is used to read the signal from the PING */
   pinMode(pingPin, INPUT);
   duration = pulseIn(pingPin, HIGH);
   
   //trigger 2nd sensor

   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2,LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2,HIGH);
   delayMicroseconds(5);
   digitalWrite(pingPin2,LOW);

   pinMode(pingPin2, INPUT);
   duration2 = pulseIn(pingPin2, HIGH);

   //trigger 3rd sensor

   pinMode(pingPin3, OUTPUT);
   digitalWrite(pingPin3,LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin3,HIGH);
   delayMicroseconds(5);
   digitalWrite(pingPin3,LOW);

   pinMode(pingPin3, INPUT);
   duration3 = pulseIn(pingPin3, HIGH);
   
   // The same pin is used to read the signal from the PING))):a HIGH  
   // pulse whose duration is the time (in microseconds) from the sending  
   // of the ping to the reception of its echo off of an object.
  
   
   
   
   
   // convert the time into a distance
   
   cm = microsecondsToCentimeters(duration);
   cm2= microsecondsToCentimeters(duration2);
   cm3 = microsecondsToCentimeters(duration3);
   
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   Serial.print(cm2);
   Serial.print("cm2");
   Serial.println();
   Serial.print(cm3);
   Serial.print("cm3");
   Serial.println();
   delay(500); 
   }
 
 
 long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
  // The ping travels out and back, so to find the distance of the 
  // object we take half of the distance travelled. 
  return microseconds / 29 / 2; 
 }
