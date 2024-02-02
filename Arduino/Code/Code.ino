#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;  // Variabile per tenere traccia del tempo trascorso
const long interval = 500;     // Intervallo di tempo desiderato tra le letture (in millisecondi)

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();  // Ottieni il tempo corrente in millisecondi

  if (currentMillis - previousMillis >= interval) {
    // È trascorso l'intervallo di tempo desiderato, esegui la lettura
    previousMillis = currentMillis;

    float temperatura = dht.readTemperature();
    float umidita = dht.readHumidity();

    if (isnan(temperatura) || isnan(umidita)) {
      Serial.println("Errore nella lettura del sensore DHT!");
      return;
    }

    Serial.print("Tempo trascorso: ");
    Serial.print(currentMillis / 1000);  // Converti millisecondi in secondi
    Serial.print("s\tTemperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C\tUmidità: ");
    Serial.print(umidita);
    Serial.println(" %");
  }
}
