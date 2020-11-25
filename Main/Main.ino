#include <QTRSensors.h>
#include <MagAlpha.h>




QTRSensors qtr;
MagAlpha magAlpha;
uint16_t sensorValues[6];



void setup()
{

  pinMode(13, OUTPUT);
  Serial.begin(115200);
  encoders_init();
  calibration();


}

void loop() {


  uint16_t L = magAlpha.readAngleRaw16();

  uint16_t position = qtr.readLineWhite(sensorValues);


  Serial.println(L);
  delay(20);

}
