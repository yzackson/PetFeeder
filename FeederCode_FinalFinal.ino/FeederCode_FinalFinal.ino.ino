#include <HX711.h>

// DEFINIÇÕES DE PINOS
#define pinDT  2
#define pinSCK  3
#define pinMotor 7

// DECLARAÇÃO DE VARIÁVEIS
float weight = 0;
char serial;

// INSTANCIANDO OBJETOS
HX711 scale;

void setup() {
  Serial.begin(9600);

  pinMode(pinMotor, OUTPUT); // CONFIGURA O PINO DO MOTOR/RELE
  
  scale.begin(pinDT, pinSCK); // CONFIGURANDO OS PINOS DA BALANÇA
  scale.set_scale(-2285.000); // DETERMINA A ESCALA

  delay(100);
  scale.tare(); // ZERANDO A BALANÇA PARA DESCONSIDERAR A MASSA DA ESTRUTURA
}

void loop() {
  weight = scale.get_units();
  Serial.print(weight);
  serial = Serial.read();
  if (serial == 'A') {
    digitalWrite(pinMotor, LOW);
  } else {
    digitalWrite(pinMotor, HIGH);
  }
  delay(20);
}
