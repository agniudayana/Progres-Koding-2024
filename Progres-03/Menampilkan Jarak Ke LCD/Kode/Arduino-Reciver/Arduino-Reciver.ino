#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x20, 16, 2);
String terima;

void setup()
{
 Serial.begin(9600);
 Serial.println("Arduino Reciver");
  
 lcd.init();
 lcd.clear();         
 lcd.backlight(); 
}

void loop()
{
  if(Serial.available()){
  	terima = Serial.readString();
    terima.trim();
    Serial.println(terima);
    lcd.setCursor(2,0);
	lcd.print("Jarak 1 : ");
    lcd.setCursor(8,1);
	lcd.print(terima);
    lcd.print(" CM");

    
    delay(100);
  }
  
}