#include <ArduinoJson.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(12);
DallasTemperature sensor(&oneWire);
 
void setup(void) 
{ 
  Serial.begin(9600);
  sensor.begin();
  
 pinMode(7, INPUT);
 pinMode(8, INPUT);
 pinMode(A0, INPUT);

} 
void loop(void) 
{ 
  sensor.requestTemperatures();
  
  StaticJsonDocument<100> dataArduino;
  
  dataArduino["Temperature"] = sensor.getTempCByIndex(0);
  dataArduino["Button1"] = digitalRead(7);
  dataArduino["Button2"] = digitalRead(8);
  dataArduino["Analog"] = analogRead(A0);
  
  char buffer[100];
 
  serializeJson(dataArduino, buffer);
 
  Serial.println(buffer);
  
  delay(800);
 
} 