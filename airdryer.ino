#include "DHT.h"

#define DHTPIN 2
#define RELAYPIN 3

#define RH_LOW 45
#define RH_HIGH 55

#define DHTTYPE DHT22   // (AM2302)

DHT dht(DHTPIN, DHTTYPE);
int airdryer_state = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, HIGH);

  Serial.println("Airdryer control started!");
}

void loop() {
  // Wait two seconds between measurements. DHT 22 can't read too often.
  delay(2000);

  float h = dht.readHumidity(); //in percent
  float t = dht.readTemperature(); // in Celsius, default

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // You can connect to serial console and take a look at temp and humidity
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  if ((h >= RH_HIGH ) && (airdryer_state == 0))
  {
    digitalWrite(RELAYPIN, LOW);
    Serial.println("Enabled Airdryer!");
    airdryer_state = 1;
  } else if ((h <= RH_LOW) && (airdryer_state == 1))
  {
    digitalWrite(RELAYPIN, HIGH);
    Serial.println("Disabled Airdryer!");
    airdryer_state = 0;
  }

}
