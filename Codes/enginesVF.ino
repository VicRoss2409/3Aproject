#include<Servo.h>

//décla varibales joystick
const int pinX = A0;
const int pinY = A1;
const int pinBouton = 2;
int boutonStateAv = 3;
int boutonStateAr = 4;
int boutonStateDr = 5;
int boutonStateGa = 6;
float pot = 7;


int Avant = 0;
int Arriere = 0;
int Droite = 0;
int Gauche = 0;


//décla variables moteur
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;
Servo ESC1V;
Servo ESC2V;

void setup() {

  Serial.begin(9600);
  
  ESC1.attach(A2, 1000, 2000); // ESC attaché au pin5, avec des pic de courant de 1000 à 2000
  ESC2.attach(A3, 1000, 2000);
  ESC3.attach(A4, 1000, 2000);
  ESC4.attach(A5, 1000, 2000);
  ESC1V.attach(A6, 1000, 2000); 
  ESC2V.attach(A7, 1000, 2000);

  pinMode(boutonStateAv,INPUT);
  pinMode(boutonStateAr,INPUT);
  pinMode(boutonStateDr,INPUT);
  pinMode(boutonStateGa,INPUT);
  pinMode(pot,INPUT);

}
 
void loop() {
  int X = 0;
  int Y = 0;
  
  //on lit les valeurs
  X = analogRead(pinX);
  X = map(X, 0, 1023, 0, 180);
      
  Y = analogRead(pinY);
  Y = map(Y, 0, 1023, 0, 180);
  
  vitesse = analogRead(pot);

  Avant=digitalRead(boutonStateAv);
  Arriere=digitalRead(boutonStateAr);
  Droite=digitalRead(boutonStateDr);
  Gauche=digitalRead(boutonStateGa);


  if (Avant == HIGH && (Arriere||Droite||Gauche)== LOW){     // Button is pushed when LOW, not HIGH
    
    Serial.println("Av");
    ESC1.write(120);
    ESC2.write(120);
    ESC3.write(-120);
    ESC4.write(-120);      
  }

  else if (Arriere == HIGH && (Avant||Droite||Gauche)== LOW){     // Button is pushed when LOW, not HIGH
    // turn LED on
    Serial.println("Ar");
    ESC1.write(-120);
    ESC2.write(-120);
    ESC3.write(120);
    ESC4.write(120);
  }

  else if (Droite == HIGH && (Arriere||Avant||Gauche)== LOW){     // Button is pushed when LOW, not HIGH
    // turn LED on:
    Serial.println("D");
    ESC1.write(120);
    ESC2.write(90);
    ESC3.write(90);
    ESC4.write(120);
  }

  else if (Gauche == HIGH && (Arriere||Droite||Avant)== LOW){     // Button is pushed when LOW, not HIGH
    // turn LED on:
    Serial.println("L");
    ESC1.write(90);
    ESC2.write(120);
    ESC3.write(120);
    ESC4.write(90);
  }

  else {
    // turn LED off:
    Serial.println("None");
    ESC1.write(90);
    ESC2.write(90);
    ESC3.write(90);
    ESC4.write(90); 
 
  }

 
}