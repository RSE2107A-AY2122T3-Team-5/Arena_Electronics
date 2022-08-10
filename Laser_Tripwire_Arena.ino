/*  
 *   Project Name : Laser Tripwire Gantry
 *   Author: Calvin Khor
 *   Version: 2.0
 *   Date Last Editted:
 *                      17/ 06/22 - Added output for blinking light for 2 gantries.
 *                      19/ 06/22 - Added servo motor function for gantry
 */
#include<Servo.h>
Servo myservo;


/* delcaration for servo motor gantry function */
const int trigPin = 3;
const int photo3 = 5;

/* declaration for LED gantry 1 & 2 */
const int photo1 = 7;
const int photo2 = 8;
const int LED1 = 9;
const int LED2 = 10;
const int LED3 = 11;
const int LED4 = 12;

void setup() {
  /*Setup for gantry servo*/
  myservo.attach(6);        //Servo setup
  pinMode(trigPin,OUTPUT);  
  pinMode(trigPin,INPUT);

  /* Setup for gantry 1 and 2 LEDs */
  pinMode(LED1, OUTPUT);    //gantry 1 LED LEFT
  pinMode(LED2, OUTPUT);    //gantry 1 LED RIGHT
  pinMode(LED3, OUTPUT);    //gantry 2 LED LEFT
  pinMode(LED4, OUTPUT);    //gantry 2 LED RIGHT
  Serial.begin(9600);       //start the serial monitor
  digitalWrite(LED1,LOW);   //set LED to low 
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  pinMode(photo1,INPUT_PULLUP);   //pinout for photovoltaic sensor 1
  pinMode(photo2,INPUT_PULLUP);   //pinout for photovoltaic sensor 2
}

void loop() {

  /* For gantry with servo*/
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);

delayMicroseconds(10);
digitalWrite(trigPin,LOW);


if(digitalRead(photo3)==LOW){   //if laser sensor detects an object , sets servo to 90 degrees, else sets to 0 degrees

myservo.write(90);
}
else{
myservo.write(0);}



/* for gantry 1 and 2 with LEDs */

  if (digitalRead(photo1)==LOW) {   // if laser sensor is not detected for gantry 1 , perform blinking
    digitalWrite(LED1,HIGH);        
    delay(100);
    digitalWrite(LED1,LOW);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED2, LOW);
    delay(100);
    
  }
  else {
   digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    delay(100);
  }
 if(digitalRead(photo2)==LOW){   //if laser sensor is not detected for gantry 2 , perform blinking
  
  digitalWrite(LED3,HIGH); 
  delay(100);
  digitalWrite(LED3,LOW);
  delay(100);
  digitalWrite(LED4,HIGH);
  delay(100);
  digitalWrite(LED4,LOW);
  delay(100);
 } 
 
 else {                                                              
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    delay(100);
 }
 }
