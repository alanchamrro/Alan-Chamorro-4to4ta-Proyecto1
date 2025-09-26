int temperatura;
int celsius;
int luz_amb;
void setup()
{
  pinMode( 3  , OUTPUT);
  pinMode( 5  , OUTPUT);
  pinMode( 6  , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  temperatura = analogRead(A0);
  celsius = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println("El nivel de temperatura actual es:");
  Serial.println(celsius);
  
  luz_amb = analogRead(A1);
  Serial.println(luz_amb);
  delay(100);
  luz_amb = map(luz_amb,722, 1022, 0, 255);
  
  if (76 < luz_amb && luz_amb < 178){
    if (celsius>90){
    digitalWrite(6 ,LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
  }else if(celsius<18){
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, HIGH);
  }
  else{
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, HIGH);
  }}
  else{
    digitalWrite(6, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }
  delay(1000);
  
}