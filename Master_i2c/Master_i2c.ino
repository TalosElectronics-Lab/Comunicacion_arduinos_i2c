/*
 * taloselectronics.com
 * Rafael Lozano Rolon
 * soporte@taloselectronics.com
 * Maestro manda informacion esclavo la recibe.
*/

#include <Wire.h>

#define Btn_1 2
#define Btn_2 3
#define Btn_3 4
#define Btn_4 5

//Maquina de estados para encender o apagar
#define Proceso_1 'a'
#define Proceso_2 'b'
#define Proceso_3 'c'
#define Proceso_4 'd'

const byte direccion=0x05;
void setup() {

  Wire.begin();//Unimos este dispositivo al bus I2C como maestro
  Serial.begin(9600);
  pinMode(Btn_1, INPUT_PULLUP);
  pinMode(Btn_2, INPUT_PULLUP);
  pinMode(Btn_3, INPUT_PULLUP);
  pinMode(Btn_4, INPUT_PULLUP);
  
}

void loop() {
  if(digitalRead(Btn_1))
  {
    while(digitalRead(Btn_1))
    {
      Serial.println("Suelta el boton");
      delay(10);// no hacer nada hasta que se suelte el boton.
    }
    //Cuando se solto 
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(direccion);
    // Enviamos la informacion
    Wire.write(Proceso_1);
    // Paramos la transmisión
    Wire.endTransmission();
  }

  if(digitalRead(Btn_2))
  {
    while(digitalRead(Btn_2))
    {
      Serial.println("Suelta el boton");
      delay(10);// no hacer nada hasta que se suelte el boton.
    }
    //Cuando se solto 
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(direccion);
    // Enviamos la informacion
    Wire.write(Proceso_2);
    // Paramos la transmisión
    Wire.endTransmission();
  }
  if(digitalRead(Btn_3))
  {
    while(digitalRead(Btn_3))
    {
      Serial.println("Suelta el boton");
      delay(10);// no hacer nada hasta que se suelte el boton.
    }
    //Cuando se solto 
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(direccion);
    // Enviamos la informacion
    Wire.write(Proceso_3);
    // Paramos la transmisión
    Wire.endTransmission();
  }
  if(digitalRead(Btn_4))
  {
    while(digitalRead(Btn_4))
    {
      Serial.println("Suelta el boton");
      delay(10);// no hacer nada hasta que se suelte el boton.
    }
    //Cuando se solto 
    // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(direccion);
    // Enviamos la informacion
    Wire.write(Proceso_4);
    // Paramos la transmisión
    Wire.endTransmission();
  }

}
