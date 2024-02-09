String kirim;

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  
  if(Serial.available()){
  	kirim = Serial.readString();
    Serial.print(kirim);
    Serial.println("");
    delay(100);
  }  
}
