/*
   taloselectronics.com
   Rafael Lozano Rolon
   soporte@taloselectronics.com
   ESCLAVO ARDUINO UNO
*/

#include <Wire.h>

#define Rele_1 2
#define Rele_2 3
#define Rele_3 4
#define Rele_4 5

//Maquina de estados para encender o apagar
#define Proceso_1 'a'
#define Proceso_2 'b'
#define Proceso_3 'c'
#define Proceso_4 'd'

const int direccion = 0x5;
volatile char Menu = 0;
void setup() {

  Wire.begin(direccion);//Unimos este dispositivo al bus I2C como esclavo
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
  pinMode(Rele_1, OUTPUT);
  pinMode(Rele_2, OUTPUT);
  pinMode(Rele_3, OUTPUT);
  pinMode(Rele_4, OUTPUT);

  //Condiciones iniciales.
  digitalWrite(Rele_1, HIGH);
  digitalWrite(Rele_2, HIGH);
  digitalWrite(Rele_3, HIGH);
  digitalWrite(Rele_4, HIGH);
}

void loop() {
  delay(100);
  switch (Menu)
  {
    case Proceso_1:
      Proceso(200);
      break;

    case Proceso_2:
      Proceso(400);
      break;

    case Proceso_3:
      Proceso(800);
      break;

    case Proceso_4:
      digitalWrite(Rele_1, HIGH);
      digitalWrite(Rele_2, HIGH);
      digitalWrite(Rele_3, HIGH);
      digitalWrite(Rele_4, HIGH);
      break;
  }
}
void Proceso(int Tiempo)
{
  digitalWrite(Rele_1, LOW);
  delay(Tiempo);
  digitalWrite(Rele_2, LOW);
  delay(Tiempo);
  digitalWrite(Rele_3, LOW);
  delay(Tiempo);
  digitalWrite(Rele_4, LOW);
  delay(Tiempo);

  digitalWrite(Rele_1, HIGH);
  digitalWrite(Rele_2, HIGH);
  digitalWrite(Rele_3, HIGH);
  digitalWrite(Rele_4, HIGH);
  delay(Tiempo);
}
void receiveEvent(int howMany) {
  if (Wire.available())
  {
    Menu = Wire.read();
    Serial.println(Menu);
  }
}
