// Importando biblioteca
#include "DHT.h"

// Definindo modelo do DHT e os pinos de entrada
#define DHTTYPE DHT11
#define dht_dpin 2 // pino D4

// Setando o dht com o tipo DHT da biblioteca DHT.h
DHT dht(dht_dpin, DHTTYPE);

void setup() {
  // Iniciando a comunicação serial
  Serial.begin(115200);

  // Iniciando a leitura do sensor DHT
  dht.begin();
  Serial.println("Iniciando a leitura do sensor: \n \n");
  delay(500);
}

void loop() {
  // Atribuindo as leituras de umidade e temperatura para as variáveis declaradas
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Exibindo os dados obtidos pelo sensor
  Serial.print("Umidade = ");
  Serial.print(h);
  Serial.print("% ");
  
  Serial.print("Temperatura = ");
  Serial.print(t);
  Serial.println("°C");

  delay(1000);
}
