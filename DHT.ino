#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to
#define Switch 10
#define Buzzer 9
// include the library code:
#include <LiquidCrystal.h>

#define DHTTYPE DHT11   // DHT 11 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);
bool  State ;
void setup() {
  pinMode(Buzzer,OUTPUT);
  pinMode(Switch,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
 
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.print(t);
  lcd.print(" *C");
  lcd.setCursor(0,1);
  lcd.print("Humidity=");
  lcd.print(h);
  lcd.print("% ");
  delay(500);
 
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %");
    Serial.print("  Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    
  }
  if(t>=40)
  {
    digitalWrite(Buzzer,HIGH);
  }
  State=digitalRead(Switch);
  if(State==HIGH)
  {
    digitalWrite(Buzzer,LOW);
  }  
}
