void TrayektoriSinus() {
  if (modeGerak == true) {
    actual_xFR = ((xFR1 - xFR0) / 10) * 2;
    actual_yFR = ((yFR1 - yFR0) / 10) * 2;
    actual_xBR = ((xBR1 - xBR0) / 10) * 2;
    actual_yBR = ((yBR1 - yBR0) / 10) * 2;
    actual_xFL = ((xFL1 - xFL0) / 10) * 2;
    actual_yFL = ((yFL1 - yFL0) / 10) * 2;
    actual_xBL = ((xBL1 - xBL0) / 10) * 2;
    actual_yBL = ((yBL1 - yBL0) / 10) * 2;
    modeGerak = false;
  }
  if (theta <= degAkhir) {
    //KANAN ATAS
    xFR = xFR0 + (((actual_xFR * theta) / 360)) * 10;
    yFR = yFR0 + (((actual_yFR * theta) / 360)) * 10;
    zFR = zFRp * sin(theta * (M_PI / 180));
    //KANAN BAWAH
    xBR = xBR0 + (((actual_xBR * theta) / 360)) * 10;
    yBR = yBR0 + (((actual_yBR * theta) / 360)) * 10;
    zBR = zBRp * sin(theta * (M_PI / 180));
    //KIRI ATAS
    xFL = xFL0 + (((actual_xFL * theta) / 360)) * 10;
    yFL = yFL0 + (((actual_yFL * theta) / 360)) * 10;
    zFL = zFLp * sin(theta * (M_PI / 180));
    //KIRI BAWAH
    xBL = xBL0 + (((actual_xBL * theta) / 360)) * 10;
    yBL = yBL0 + (((actual_yBL * theta) / 360)) * 10;
    zBL = zBLp * sin(theta * (M_PI / 180));
    FR(xFR, yFR, zFR);
    BR(xBR, yBR, zBR);
    BL(xBL, yBL, zBL);
    FL(xFL, yFL, zFL);
    theta += Increment;
    if (theta > degAkhir) {
      theta = degAwal;
      statusGerak = false;
    }
  }
}



//=========Gerak Dinamis======//
void TransformasiGerak(float lebarY, float lbrKiri, float lbrKanan) {
  //Kanan maju duluan && Belok Kanan = lbr(+), Belok kiri = lbr(-)
  //KANAN DEPAN (FR)
  yFR_Awal = (standFR[1][0] - lebarY) + lbrKanan, yFR_Akhir = (standFR[1][0] + lebarY) - lbrKanan;
  //KANAN BELAKANG (BR)
  yBR_Awal = (standBR[1][0] - lebarY) + lbrKanan, yBR_Akhir = (standBR[1][0] + lebarY) - lbrKanan;
  //KIRI DEPAN (FL)
  yFL_Awal = (standFL[1][0] + lebarY) + lbrKiri, yFL_Akhir = (standFL[1][0] - lebarY) - lbrKiri;
  //KIRI BELAKANG (BL)
  yBL_Awal = (standBL[1][0] + lebarY) + lbrKiri, yBL_Akhir = (standBL[1][0] - lebarY) - lbrKiri;
}

void GerakDinamis(float Lebar, float tinggi, int speeds, float lKiri, float lKanan) { //lebarY : maju (+), mundur (-)
  //  Trayektori = true;
  if (!statusGerak) {
    Increment = 180 / speeds;
    switch (steps) {
      case 0 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, lKiri, lKanan);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFRp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFLp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
      case 1:
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGerak(Lebar, lKiri, lKanan);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFRp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFLp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 2 :
        degAwal = 0 + Increment;
        degAkhir = 180;
        TransformasiGerak(Lebar, lKiri, lKanan);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Akhir, xFR1 = standFR[0][0] , yFR1 = yFR_Awal, zFRp = 0;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Akhir, xBR1 = standBR[0][0], yBR1 = yBR_Awal, zBRp = 0;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Akhir, xFL1 = standFL[0][0], yFL1 = yFL_Awal, zFLp = tinggi;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Akhir, xBL1 =  standBL[0][0], yBL1 = yBL_Awal, zBLp = tinggi;
        modeGerak = true;
        statusGerak = true;
        break;
      case 3 :
        degAwal = 90 + Increment;
        degAkhir = 90;
        TransformasiGerak(Lebar, lKiri, lKanan);
        //KANAN DEPAN (FR)
        xFR0 = standFR[0][0],  yFR0 =  yFR_Awal, xFR1 = standFR[0][0] , yFR1 = yFR_Akhir, zFRp = tinggi;
        //KANAN BELAKANG (BR)
        xBR0 = standBR[0][0],  yBR0 =  yBR_Awal, xBR1 = standBR[0][0], yBR1 = yBR_Akhir, zBRp = tinggi;
        //KIRI DEPAN (FL)
        xFL0 = standFL[0][0],  yFL0 =  yFL_Awal, xFL1 = standFL[0][0], yFL1 = yFL_Akhir, zFLp = 0;
        //KIRI BELAKANG (BL)
        xBL0 = standBL[0][0],  yBL0 = yBL_Awal, xBL1 =  standBL[0][0], yBL1 = yBL_Akhir, zBLp = 0;
        modeGerak = true;
        statusGerak = true;
        break;
    }
    steps++;
    if (steps > 3) steps = 0;
  }
}

