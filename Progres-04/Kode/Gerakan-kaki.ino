void Standby() {
  steps = 0;
  theta = 0;
  degAkhir = 0;
  //KANAN DEPAN (FR)
  xFR0 = -55,  yFR0 = 55, xFR1 = -55, yFR1 = 55, zFRp = 0;
  //KANAN BELAKANG (BR)
  xBR0 = -55, yBR0 = -55, xBR1 = -55,  yBR1 = -55, zBRp = 0;
  //KIRI DEPAN (FL)
  xFL0 = 55, yFL0 = 55, xFL1 = 55,  yFL1 = 55, zFLp = 0;
  //KIRI BELAKANG (BL)
  xBL0 = 55, yBL0 = -55, xBL1 = 55,  yBL1 = -55, zBLp = 0;
  modeGerak = true;
  statusGerak = false;
}

void StandbyAwal() {
  FR(-55, 55, 20);
  BR(-55, -55, 20);
  BL(55, -55, 20);
  FL(55, 55, 20);
  KirimIntruksiGerak(512);
  delay(500);
  FR(-55, 55, 0);
  BR(-55, -55, 0);
  BL(55, -55, 0);
  FL(55, 55, 0);
  KirimIntruksiGerak(512);
}

