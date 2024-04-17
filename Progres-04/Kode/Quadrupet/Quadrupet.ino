#include <STM32FreeRTOS.h>
HardwareSerial Serial2(USART2);  //Serial Driver Servo

//Gerakan
bool statusGerak = false;
bool modeGerak = true;
int steps = 0;
float theta = 90;
float tAwal, degAwal;
float tAkhir, degAkhir;

float xFR, yFR, zFR, xFL, yFL, zFL, xBR, yBR, zBR, xBL, yBL, zBL;
float yFR_Awal, yFL_Awal, yBL_Awal, yBR_Awal, yFR_Akhir, yFL_Akhir, yBL_Akhir, yBR_Akhir;
float xFR_Awal, xFL_Awal, xBL_Awal, xBR_Awal, xFR_Akhir, xFL_Akhir, xBL_Akhir, xBR_Akhir;
float actual_xFR, actual_yFR, actual_xBR, actual_yBR, actual_xBL, actual_yBL, actual_xFL, actual_yFL;
float actual_zFR, actual_zBR, actual_zFL, actual_zBL;
//=====Input Trayektori Global=====//
//KANAN DEPAN (FR)
float xFR0, yFR0, xFR1, yFR1, zFR0, zFRp;
//KANAN BELAKANG (BR)
float xBR0, yBR0, xBR1, yBR1, zBR0, zBRp;
//KIRI DEPAN (FL)
float xFL0, yFL0, xFL1, yFL1, zFL0, zFLp;
//KIRI BELAKANG (BL)
float xBL0, yBL0, xBL1, yBL1, zBL0, zBLp;
float Increment;
//Variabel simpan sudut tiap servo
int outServo[4][3];
//Variabel Invers Kinematik
const float cx = 22;
const int fm = 53;
const int tb = 70;
int heightFront = -92, heightBack = -92;  //kelereng -94
float z, sdtcoxa, sdtcoxa1, sdtcoxa2, sdtcoxa3, sdtcoxa4, sdtrotate, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
const int legoffset[6] = { 0, 45, 135, 180, 225, 315 };
//Koordinat Awal (Standby) per Kaki :
const float standFR[3][1] = { { -55 }, { 55 }, { 0 } };  //
const float standBR[3][1] = { { -55 }, { -55 }, { 0 } };
const float standFL[3][1] = { { 55 }, { 55 }, { 0 } };
const float standBL[3][1] = { { 55 }, { -55 }, { 0 } };
float offsetCX[4] = { 0 };  //0 = FR, 1 = BR, 2 = BL, 3 = FL
float rightFM = 0, rightTB = 0, leftFM = 0, leftTB = 0;
int jmlhStep;


void setup() {
  Serial.setTx(PA9);
  Serial.setRx(PA10);
  Serial.begin(9600);

  //Serial Untuk Mengirim Data sudut ke servo
  Serial2.setTx(PA2);
  Serial2.setRx(PA3);
  Serial2.begin(1000000);

  delay(3000);
  StandbyAwal();
  delay(1000);
 
}

void loop() {
  GerakDinamis(15, 15, 6, 0, 0);
  TrayektoriSinus();
  KirimIntruksiGerak(0);
  delay(5);
}
