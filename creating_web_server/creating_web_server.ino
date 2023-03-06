// Importando bibliotecas para trabalhar com wifi
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Importando bibliotecas para trabalhar com servidor web
#include <ESP8266WebServer.h>

// Setando os dados para conexão wifi
const char* ssid = "nome_da_rede_wifi";
const char* password = "senha_da_rede_wifi";

// Setando a porta de acesso
ESP8266WebServer server(80);

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

  // Iniciando o servidor web
  server.begin();
  Serial.println("Web Server inicializado");
  delay(500);
  Serial.println("Acesse o endereço pelo: ");
  Serial.println(WiFi.localIP());

  // Setando rotas de requisições (endpoint)
  server.on("/", [] () {
    // 1º parâmetro -> Código de status de resposta HTTP
    // 2º parâmetro -> Cabeçalho da requisição
    // 3º parâmetro -> Corpo da requisição
    server.send(200, "cabeçalho da requisição", "BEM VINDO AO SERVIDOR NODEMCU");
  });

  server.on("/teste", [] () {
    server.send(200, "cabeçalho da requisição", "BEM VINDO A PAGINA TESTE");
  });
}

void loop() {
  // Função para lidar com a conexão do cliente (aplicação react native)
  // Recebe a requisição, verifica qual rota o cliente disparou e faz o retorno da mesma
  server.handleClient();
}
