#include <QTRSensors.h>
#include <MagAlpha.h>


QTRSensors qtr;
MagAlpha magAlpha;
uint16_t sensorValues[6];

int menucounts = 0;

int encoder_offset = 0;



int buttonPushCounter = 0;


# define CS_ENC_L 2
# define CS_ENC_R 3
# define TB6612_AIN1  4
# define TB6612_PWMA  5
# define TB6612_PWMB  6
# define TB6612_AIN2  7
# define TB6612_BIN1  8
# define TB6612_BIN2  9
# define BUZZER 10
# define LEDON  11
# define HR A0
# define HL A7





void setup()
{

  Serial.begin(115200);
  encoders_init();
  beep_1();


}

void loop() {

  boton_l1();
  menu_enc_count();
  wheel_scroll_1();

}
