#include "max6675.h"

const int SCK_Port = 6, CS_Port = 5, MISO_Port = 4;
MAX6675 termopar(SCK_Port, CS_Port, MISO_Port);

void begin_serial_comunication() {
  Serial.begin(9600);
  Serial.println("Iniciando a comunicação serial e a leitura do Termopar MAX6675:");
  delay(2000);
}

void print_temp(){
  double read_temperature = termopar.readCelsius();
    
  Serial.print("Temperatura: ");
  Serial.print(read_temperature);
  Serial.println(" °C");
  
  delay(1000);
}

void setup() {
  begin_serial_comunication();
}

void loop() {
  print_temp();
}
