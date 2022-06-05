/*
     Q0481-Sketch-Calibrar
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  Calibrar Balanca com módulo HX711
     DATA:    04/07/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include <HX711.h>

// DEFINIÇÕES DE PINOS
#define pinDT  2
#define pinSCK  3

// INSTANCIANDO OBJETOS
HX711 scale;

// DECLARAÇÃO DE VARIÁVEIS
float medida = 0;

void setup() {
  Serial.begin(9600);

  scale.begin(pinDT, pinSCK); // CONFIGURANDO OS PINOS DA BALANÇA
  scale.set_scale(-2285.000); // LIMPANDO O VALOR DA ESCALA

  //delay(2000);
  scale.tare(); // ZERANDO A BALANÇA PARA DESCONSIDERAR A MASSA DA ESTRUTURA
}

void loop() {

  medida = scale.get_units(); // SALVANDO NA VARIAVEL O VALOR DA MÉDIA DE 5 MEDIDAS

  //seta pra zero se o número for menor que o mínimo 0
  //if (medida <= 0) {
    //medida = 0.000;
  //}
  
  Serial.print(round(medida)); // ENVIANDO PARA MONITOR SERIAL A MEDIDA COM 3 CASAS DECIMAIS
  delay(10);
}
