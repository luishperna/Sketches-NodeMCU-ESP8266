// Importando bibliotecas para trabalhar com wifi
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Setando os dados para conexão wifi
const char* ssid = "nome_da_rede_wifi";
const char* password = "senha_da_rede_wifi";

void setup() {
  // Iniciando comunicação serial
  Serial.begin(115200);

  // Iniciando comunicação wifi
  WiFi.begin(ssid, password);

  // Esperando enquanto o status de conexão for diferente de conectado
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  // Após conectar com wifi
  Serial.println("");
  Serial.print("NodeMCU conectado no IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Conexão efetuada com sucesso!");
}

void loop() {

}
