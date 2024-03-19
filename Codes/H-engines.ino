#include<Servo.h>

//décla varibales joystick 
const int pinX = A0;
const int pinY = A1;
const int pinBouton = 2;

//décla variables moteur
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;


void setup() {
  pinMode(pinBouton , INPUT_PULLUP);   //on active la résistance pull up 
  Serial.begin(9600);
  //ESC gauche
  ESC1.attach(5, 1000, 2000); // ESC attaché au pin5, avec des pic de courant de 1000 à 2000
  ESC2.attach(6, 1000, 2000);
  ESC3.attach(9, 1000, 2000);
  ESC4.attach(11, 1000, 2000);
}
 
void loop() {
  int X = 0;
  int Y = 0;
  bool boutonValeur = false;
 
  //on lit les valeurs
  X = analogRead(pinX);
  X = map(X, 0, 1023, 0, 180);
      
  Y = analogRead(pinY);
  Y = map(Y, 0, 1023, 0, 180);
   
  boutonValeur = digitalRead(pinBouton);

  // tourner à gauche
  if (X<=80){
    ESC1.write(Y);
    ESC2.write(X);
    ESC3.write(X);
    ESC4.write(Y);
  }
  
  //tourner à droite
  else if (X>=100){
    ESC1.write(X);
    ESC2.write(Y);
    ESC3.write(Y);
    ESC4.write(X);
  }
  
  //position initiale joystick
  else{
    ESC1.write(90);
    ESC2.write(90);
    ESC3.write(90);
    ESC4.write(90);
  }
  
// vers l'avant 
  if (Y<=80){
    ESC1.write(Y);
    ESC2.write(-Y);
    ESC3.write(Y);
    ESC4.write(-Y);
  }

// vers l'arrière
  else if (Y>=100){
    ESC1.write(-Y);
    ESC2.write(Y);
    ESC3.write(-Y);
    ESC4.write(Y);
  }

  //position initiale joystick
  else{
    ESC1.write(90);
    ESC2.write(90);
    ESC3.write(90);
    ESC4.write(90);
  }

  //montrer les valeurs à l'écran
  Serial.print("X:" );
  Serial.print(X);
  Serial.print(" | Y: ");
  Serial.print(Y);
  Serial.print(" | Pulsateur: ");
  Serial.println(boutonValeur);
  delay(1000);
}