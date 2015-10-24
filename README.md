# Airdryer controller

This little project controls an airdryer via a relay module.
When the relative humidity is bigger than 55%, it will turn on the relay,
powering on the device. After the relative humidity is under 45, it will turn it
off.

## Wiring

Connect your DHT22 sensor to Pin 2 and the relay module to pin 3.


## Settings

Set the pins used for relay and humidity sensor
DHTPIN 2
RELAYPIN 3

Set when to start and stop the airdryer
RH_LOW 45
RH_HIGH 55

Type of the sensor (DHT11, DHT21 or DHT22)
DHTTYPE DHT22
