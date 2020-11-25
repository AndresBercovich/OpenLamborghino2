


void encoders_init() {
  
  magAlpha.begin(1000000, MA_SPI_MODE_3, 2);

}






void calibration () {
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {
    A1, A2, A3, A4, A5, A6
  }, 6);

  qtr.setEmitterPin(11);
  delay(500);

  digitalWrite(13, HIGH);

  for (uint16_t i = 0; i < 100; i++)
  {
    qtr.calibrate();
  }

  digitalWrite(13, LOW);


  for (uint8_t i = 0; i < 6; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (uint8_t i = 0; i < 6; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();

}
