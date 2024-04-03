int pressionPin = A0;
int valeur;
float tension;
float pression;

void setup(){
  Serial.begin(9600);
  pinMode(pressionPin,INPUT);
}

void loop(){
  valeur = analogRead(pressionPin);
  tension = valeur * (3.5/1023.0)*10;
  pression = tension *218.5+107.3

  Serial.println("Pression=");
  Serial.println(pression);
  Serial.println("hPa");
  delay(1000);
}  