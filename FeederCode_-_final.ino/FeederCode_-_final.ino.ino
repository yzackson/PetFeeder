#include <Stepper.h>
#include <HX711.h>

// DEFINIÇÕES DE PINOS
#define pinDT  2
#define pinSCK  3

// DECLARAÇÃO DE VARIÁVEIS
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor
float weight = 0;
char serial;

// INSTANCIANDO OBJETOS
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // initialize the stepper library on pins 8 through 11
HX711 scale;

void setup() {
  Serial.begin(9600);

  scale.begin(pinDT, pinSCK); // CONFIGURANDO OS PINOS DA BALANÇA
  scale.set_scale(-2285.000); // DETERMINA A ESCALA

  delay(100);
  scale.tare(); // ZERANDO A BALANÇA PARA DESCONSIDERAR A MASSA DA ESTRUTURA
  
  // set the stpermotor speed at 60 rpm:
  myStepper.setSpeed(60);
}

void loop() {
  weight = scale.get_units();
  Serial.print(weight);
  serial = Serial.read();
  if (serial == 'A') {
    myStepper.step(stepsPerRevolution);
  }
  delay(20);
}
