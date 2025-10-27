#include <Servo.h>

Servo cancela;

const int trigPin = 2;
const int echoPin = 3;
const int ledVerde = 6;
const int ledVermelho = 7;
const int servoPin = 9;

long duracao;
int distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  cancela.attach(servoPin);
  cancela.write(0); // cancela fechada
}

void loop() {
  // Envia sinal ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mede o tempo de resposta
  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Se objeto estiver a menos de 15 cm, abre a cancela
  if (distancia <= 15) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    cancela.write(90); // abre
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    cancela.write(0); // fecha
  }

  delay(500);
}
