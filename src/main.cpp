/**
* @file main.cpp
 * @brief MG995 Closed-Loop Axis Control System
 * @author Mohan Sharma
 * @date YYYY-MM-DD
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 */
#include <Arduino.h>
#include<Servo.h>
Servo myservo;
int echopin=10;
//initilise the trigpin and echopin
int trigpin=9;
void setup() {
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
    Serial.begin(9600);
    myservo.attach(3);


}





void loop() {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,0);
    long duration=pulseIn(echopin,1);
    long distance=(duration*0.034)/2;
    if(distance<15){
        myservo.write(90);
    }
    else{
        myservo.write(0);

    }
    Serial.print("Distance");
    Serial.print(distance);
    Serial.println("cm");
    delay(500);
    // put your main code here, to run repeatedly:

}
