String terima;

void setup()
{
 Serial.begin(9600);
 Serial.println("Arduino Reciver");
}

void loop()
{
  if(Serial.available()){
  	terima = Serial.readString();
    Serial.println(terima);
    delay(100);
  }
}
