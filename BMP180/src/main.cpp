#include <Wire.h>
#include <BMP180.h>
#include <arduino.h>
#define seaLevelPressure_hPa 1013.25

BMP180 bmp;
  
void setup() {
  Serial.begin(9600);
  bmp.init();
}
  
void loop() {
  unsigned int ut = bmp.bmp180ReadUT();
  unsigned long up = bmp.bmp180ReadUP();
  float temperature = bmp.bmp180GetTemperature(ut);
  long pressure = bmp.bmp180GetPressure(up);
  float altitude = bmp.calcAltitude(pressure);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");
  delay(1000);
}
