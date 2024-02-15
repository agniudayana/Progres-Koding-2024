#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x20, 16, 2);


void setup()
{
    Serial.begin(9600);

    lcd.init();
    lcd.clear();
    lcd.backlight();
}

void loop()
{

    lcd.setCursor(6, 0);
    lcd.print("Halo");
    lcd.setCursor(3, 1);
    lcd.print("Hello World");

}