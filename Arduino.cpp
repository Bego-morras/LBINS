#include "HX711.h"
 
#define DEBUG_HX711

// Parámetro para calibrar el peso y el sensor
-------------------------------------------> float factor_calibración = 

/* pin2 ->clk
 *  pin3 -> out
 * 5V -> Vcc
 * GND ->gnd
 */
byte pinData =3;
byte pinCLk =2;

// Objeto HX711
HX711 bacula; 

void setup() {
 //iniciar la comunicación
 Serial.begin(9600);
 Serial.println("Inicio del sensor")

  //Inicio sensor
  bascula.begin(pinData, pinClk);
  // Aplicar la calibración
  bascula.set_scale(factor_calibracion);
  // Iniciar la tara, bascula a 0
  bascula.tare();

  


}





void loop() {

  Serial.print("[HX7] Leyendo: ");
  Serial.print(bascula.get_units(), 1);
  Serial.print(" Kg");
  Serial.println();

// Obtener información desde el monitor serie
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == '+')
      factor_calibracion += 10;
    else if (temp == '-')
      factor_calibracion -= 10;
  }

}