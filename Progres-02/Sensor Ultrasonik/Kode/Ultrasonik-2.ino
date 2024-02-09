//deklarasi pin echo dan triger ultrasonik
int Trigger1 = 7;
int Echo1 = 6;

int Trigger2 = 8;
int Echo2 = 9;

void setup() {
  //atur triger sebagai output dan echo sebagai input
  pinMode(Trigger1, OUTPUT);
  pinMode(Echo1, INPUT);
  
  pinMode(Trigger2, OUTPUT);
  pinMode(Echo2, INPUT);

  //Memulai komunikasi serial
  Serial.begin(9600);
}

void loop() {
  
 Serial.print("Sensor 1 dengan jarak : ");
 ultrasonik(Trigger1,Echo1);
 Serial.println("");
  
 Serial.print("Sensor 2 dengan jarak : ");
 ultrasonik(Trigger2,Echo2);
 Serial.println("");
}

void ultrasonik(int trg, int ech){

 //Triger memancarkan gelombang
  digitalWrite(trg, LOW);
  delayMicroseconds(2);
  digitalWrite(trg, HIGH);
  delayMicroseconds(2);
  digitalWrite(trg, LOW);

  //echo menangkap gelombang
  long timedelay = pulseIn(ech, HIGH);

  //Melakukan perhitungan agar hasil yang didapat dalam jarak cm
  int distance = 0.0343 * (timedelay / 2);

  //Print nilai pembacaan sensor 
  Serial.print("Sensor : ");
  Serial.print(distance);
  Serial.println(" cm");

  //jeda selama 500 milisecond
  delay(500);
}