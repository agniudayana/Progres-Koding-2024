String kirim;
const int TRIGPIN = 10;
const int ECHOPIN = 9;
long timer;
int jarak;

void setup()
{
 Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop()
{
  String hasil = String(distance());
  Serial.print(hasil);
  Serial.println("");
  delay(1000);
  if(Serial.available()){
  	kirim = Serial.readString();
    Serial.print(kirim);
    Serial.println("");
    delay(100);
  }  
}

int distance(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   

  timer = pulseIn(ECHOPIN, HIGH);
  jarak = 0.0343 * (timer / 2);
  delay(1000);

  return jarak;
}
