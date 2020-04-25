#include <DallasTemperature.h>
#include <OneWire.h>

#include <LiquidCrystal.h>

int tsensor=13;
float temperature=0;

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);

OneWire oneWirePin(tsensor);
DallasTemperature sensors(&oneWirePin);

void setup() {
  Serial.begin(115200);
  
  sensors.begin();
  
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Temp ");
  LCD.setCursor(11,0);
  LCD.print("C");
  

}

void loop() {
  
  sensors.requestTemperatures();
  Serial.println("");

  temperature = sensors.getTempCByIndex(0);

  Serial.print("Temperture is: ");
  Serial.print(temperature);
  Serial.print("°C");

  LCD.setCursor(5,0);
  LCD.print(temperature);
  
  
  

}
