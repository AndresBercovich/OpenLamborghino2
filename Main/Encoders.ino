

int scroll_state = 0;
int last_scroll_state = 0;
float scroll = 0;

byte menu_level_1 = 0;
byte menu_level_2 = 0;
byte menu_level_3 = 0;

void encoders_init() {

  magAlpha.begin(1000000, MA_SPI_MODE_3, CS_ENC_L);
  encoder_offset = (magAlpha.readAngleRaw8() >> 3);
  encoder_offset = (magAlpha.readAngleRaw8() >> 3);


}




int l_counts = 0;





void menu_enc_count() {

  int counts =  magAlpha.readAngleRaw8() >> 3 ;


  if (counts < encoder_offset) {
    counts = ((magAlpha.readAngleRaw8() >> 3 ) - encoder_offset) + 32;
  } else {
    counts =  ((magAlpha.readAngleRaw8() >> 3 ) - encoder_offset);
  }



  if (counts >= 0 && counts < 16) {
    counts = counts + 16;
  } else {

    counts = counts - 16;

  }



  if (l_counts - counts > 16) {

    menucounts++;

  }

  if (l_counts - counts < -16) {

    menucounts--;

  }

  l_counts = counts;

  scroll = -1 * (menucounts * 31 + counts);





}



void wheel_scroll_1() {
  scroll_state = scroll;
  if (abs(scroll_state - last_scroll_state) >= 64) {
    if (scroll_state > last_scroll_state) {
      menu_level_1++;


      if (menu_level_1 > 3) {
        menu_level_1 = 3;
        beep_3();
      } else {
        beep_song_2();
      }
      Serial.println(menu_level_1);


    } else {

      if (menu_level_1 >= 2) {
        menu_level_1--;
        beep_song_1();
      } else {
        menu_level_1 = 1;
        beep_3();
      }
      Serial.println(menu_level_1);


    }

    last_scroll_state = scroll_state;
  }
}




void wheel_scroll_2() {
  scroll_state = scroll;
  if (abs(scroll_state - last_scroll_state) >= 64) {
    if (scroll_state > last_scroll_state) {
      menu_level_2++;


      if (menu_level_2 > 4) {
        menu_level_2 = 4;
        beep_3();
      } else {
        beep_song_2();
      }
      Serial.println(menu_level_2);


    } else {

      if (menu_level_2 >= 2) {
        menu_level_2--;
        beep_song_1();
      } else {
        menu_level_2 = 1;
        beep_3();
      }
      Serial.println(menu_level_2);


    }

    last_scroll_state = scroll_state;
  }
}
