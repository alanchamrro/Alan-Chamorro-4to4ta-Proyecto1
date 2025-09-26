// Incluimos la librería para Servo
#include <Servo.h>


Servo servoArriba;   
Servo servoAbajo;    


int botonAvanzar = 3;    
int botonRetroceder = 2; 


int pos = 90;   
int paso = 10;  

void setup() {
 
  servoArriba.attach(A2);  
  servoAbajo.attach(A1);  

  
  pinMode(botonAvanzar, INPUT);        
  pinMode(botonRetroceder, INPUT);     // Si no, cambiar a INPUT_PULLUP

  // Los llevo a la posición inicial
  servoArriba.write(pos);
  servoAbajo.write(pos);
}

void loop() {
  
  int estadoAvanzar = digitalRead(botonAvanzar);
  int estadoRetroceder = digitalRead(botonRetroceder);

  
  if (estadoAvanzar == HIGH) {
    avanzar();
    delay(200);  
  }

 
  if (estadoRetroceder == HIGH) {
    retroceder();
    delay(200);
  }
}


void avanzar() {
  if (pos + paso <= 180) {   
    pos = pos + paso;
    servoArriba.write(pos);
    servoAbajo.write(pos);
  }
}


void retroceder() {
  if (pos - paso >= 0) {     
    pos = pos - paso;
    servoArriba.write(pos);
    servoAbajo.write(pos);
  }
}