#define rojopin 3
#define verdepin 4
bool deteccion = LOW;
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  deteccion = digitalRead(2);
  if (deteccion == HIGH){
    digitalWrite(rojopin, HIGH);
    digitalWrite(verdepin, LOW);

  }
  else{
    digitalWrite(rojopin, LOW);
    digitalWrite(verdepin, HIGH);
  }
}