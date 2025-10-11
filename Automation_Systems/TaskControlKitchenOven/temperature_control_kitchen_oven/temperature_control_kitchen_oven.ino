#include "max6675.h"

const int SCK_Port = 6, CS_Port = 5, MISO_Port = 4; //define as portas de comunicacáo que serao utilizadas do termopar
MAX6675 termopar(SCK_Port, CS_Port, MISO_Port);

const int zero_crossing = 11, upper_resistance = 10, lower_resistance = 9, operation_mode = 8; //

unsigned long time, zero_time;
double temperature;

void begin_serial_comunication() {
  Serial.begin(9600);
  Serial.println("Iniciando a comunicação serial e a leitura do Termopar MAX6675:");
  delay(2000);
}

void print_temp(){  
  Serial.print(" Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

void print_time(){  
  Serial.print("Tempo: ");
  Serial.print(time/1000);
  Serial.print("s |");
}

void control_on_off(float set_pt) {
  if (temperature >= set_pt) {
    digitalWrite (lower_resistance,LOW);
    digitalWrite (upper_resistance,LOW);
  }

  else {
    digitalWrite (lower_resistance,HIGH);
    digitalWrite (upper_resistance,HIGH);
  } 
}

void angle_trigger_control(float set_pt) {
  if (temperature >= set_pt) {
     digitalWrite (lower_resistance,LOW);
    digitalWrite (upper_resistance,LOW);
  }

  else{
    if ((digitalRead(zero_crossing)) == HIGH) {
      zero_time = millis();
  
      digitalWrite (lower_resistance,LOW);
      digitalWrite (upper_resistance,LOW);
    }
  
    if ((zero_time+5) == time) {
      
      digitalWrite (lower_resistance,HIGH);
      digitalWrite (upper_resistance,HIGH); 
    }
  }
}

void setup() {
  begin_serial_comunication();

  pinMode(upper_resistance,OUTPUT);
  pinMode(lower_resistance,OUTPUT);
  pinMode(operation_mode,OUTPUT);

  digitalWrite (operation_mode,HIGH);

  pinMode(zero_crossing,INPUT_PULLUP);
  
}


void loop() {
  time = millis();
  float set_point = 110;
//
  angle_trigger_control(set_point);
//  control_on_off(set_point);
    
  if ((time%1000) == 0) {
    print_time();

    temperature = termopar.readCelsius();
    print_temp();
  } 

}
