//deklarasi pin echo dan triger ultrasonik
int Trigger = 7;
int Echo = 6;

void setup() {
  //atur triger sebagai output dan echo sebagai input
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  //Memulai komunikasi serial
  Serial.begin(9600);
}

void loop() {
  //Triger memancarkan gelombang
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trigger, LOW);

  //echo menangkap gelombang
  long timedelay = pulseIn(Echo, HIGH);

  //Melakukan perhitungan agar hasil yang didapat dalam jarak cm
  int distance = 0.0343 * (timedelay / 2);

  //Print nilai pembacaan sensor 
  Serial.print("Sensor : ");
  Serial.print(distance);
  Serial.println(" cm");

  //jeda selama 500 milisecond
  delay(500);
}