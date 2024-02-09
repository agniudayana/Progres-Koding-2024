String terima;
#include <Servo.h>

Servo myservo;
int pos;


void setup()
{
 Serial.begin(9600);
 Serial.println("Arduino Reciver");
 myservo.attach(8);
}

void loop()
{
  if(Serial.available()){
  	terima = Serial.readString();
    Serial.println(terima);
    pos = terima.toInt();
    gerakServo(pos);
    delay(100);
  }
}

void gerakServo( int a) {
  if (a > 180){
    a = 180;
  }else if ( a < 0){
    a = 0;
  }else{
  	myservo.write(a); 
  }
  delay(100); 
}