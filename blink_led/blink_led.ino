void setup() {
  // Setando o pino D4 como pino da LED (saída)
  pinMode(D1, OUTPUT);
  // Iniciando a comunicação serial com velocidade de 115200
  Serial.begin(115200);

  Serial.println("Verificando o estado da led: ");
}

void loop() {
  // Piscando a LED
  digitalWrite(D1, HIGH);
  Serial.println("LED acessa");
  delay(1000);
  digitalWrite(D1, LOW);
  Serial.println("LED apagado");
  delay(1000);
}
