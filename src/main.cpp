#include <Arduino.h>
#include <string>

using namespace std;

// Définition des broches pour le capteur à ultrasons
const int trigPin = 26; // Broche de déclenchement (Trigger)
const int echoPin = 27; // Broche de réception (Echo)


// Définition de la broche de la LED
const int ledPin = 5;

void setup() {
  // Initialisation des broches du capteur à ultrasons
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialisation de la broche de la LED en mode sortie
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Déclencher une impulsion ultrasonique
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesurer la durée de l'écho
  long duration = pulseIn(echoPin, HIGH);

  // Convertir la durée en distance
  // (la vitesse du son est d'environ 0.0343 cm/microseconde)
  float distance_cm = duration * 0.0343 / 2;

  Serial.print("Distance : ");
  Serial.print(distance_cm);
  Serial.print("\n");

  // Allumer la LED si la distance est inférieure à 10 cm
  if (distance_cm < 10) {
    digitalWrite(ledPin, HIGH); // Allumer la LED
  } else {
    digitalWrite(ledPin, LOW); // Éteindre la LED
  }

  // Attendre un court instant pour éviter la surcharge du capteur
  delay(100);
}