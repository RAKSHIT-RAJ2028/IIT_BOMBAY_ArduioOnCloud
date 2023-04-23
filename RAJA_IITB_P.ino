#include <DHT.h>
#include<ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include<WiFiClient.h>
#define DHTTYPE DHT11
uint8_t DHTPIN = D1;

DHT mydht(DHTPIN,DHTTYPE);
const char* ssid = "Mahadev";
const char* password = "bholenath";
float humidity, temp;

void setup() {

  Serial.begin(9600);
  //WiFi.begin(ssid,password);
  pinMode(DHTPIN,INPUT);
  mydht.begin();
  delay(2000);
   humidity = mydht.readHumidity();
   temp = mydht.readTemperature();
   delay(2000);
}

void loop() {
  HTTPClient http;
  WiFiClient Client;
 humidity = mydht.readHumidity();
 temp = mydht.readTemperature();
 Serial.print("Humidity :");Serial.println(humidity);
 Serial.print("Temp: ");Serial.println(temp);
delay(1000);
}
