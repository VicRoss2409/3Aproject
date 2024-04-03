#include <NewPing.h>
const int trig = 8;
const int echo = 9;
long int lecture_echo = 0;
float distance = 0;
NewPing sonar(8,9);


void setup() { 
   Serial.begin(9600);
   pinMode(trig,OUTPUT);
   pinMode(echo,INPUT);
}

void loop() {
   digitalWrite(trig,HIGH);
   delayMicroseconds(60);
   digitalWrite(trig,LOW);
   lecture_echo=pulseIn(echo,HIGH);
   distance = sonar.ping_cm();
     Serial.println(distance);
     delay(60);
}

