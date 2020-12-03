

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
unsigned long l_buton_timer = 0;
unsigned int buton_timer = millis();

void beep_1() {
  noTone(BUZZER);
  tone(BUZZER, 2093, 100);  // Instant beep: 100ms, 2093 hz (C7)
}

void beep_2() {
  noTone(BUZZER);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
}

void beep_3() {
  noTone(BUZZER);
  tone(BUZZER, 1000, 50);  // Instant beep: 100ms, 4186 hz (C8)
  delay(100);
  tone(BUZZER, 1000, 50);  // Instant beep: 100ms, 4186 hz (C8)
  delay(100);
}

void beep_4() {
  noTone(BUZZER);
  tone(BUZZER, 1000, 50);  // Instant beep: 100ms, 4186 hz (C8)
  delay(100);
  tone(BUZZER, 1000, 50);  // Instant beep: 100ms, 4186 hz (C8)
  delay(100);
  delay(100);
  tone(BUZZER, 1000, 50);  // Instant beep: 100ms, 4186 hz (C8)
  delay(100);
}



void beep_level1() {
  noTone(BUZZER);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);

}

void beep_level2() {
  noTone(BUZZER);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
}

void beep_level3() {
  noTone(BUZZER);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
  tone(BUZZER, 3135, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
}


void beep_back() {
  noTone(BUZZER);
  tone(BUZZER, 1400, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
  tone(BUZZER, 1400, 100);  // Instant beep: 100ms, 3135 hz (G7)
  delay(200);
}

void beep_song_1() {
  noTone(BUZZER);
  for (int i = 4000; i > 2000; i--) {

    tone(BUZZER, i);  // Instant beep: 100ms, 4186 hz (C8)
  }
  noTone(BUZZER);
}




void beep_song_2() {
  noTone(BUZZER);
  for (int i = 2000; i < 4000; i++) {

    tone(BUZZER, i);  // Instant beep: 100ms, 4186 hz (C8)
  }
  noTone(BUZZER);
}

void beep_song_3() {
  noTone(BUZZER);
  for (int i = 3000; i < 4000; i++) {

    tone(BUZZER, i);  // Instant beep: 100ms, 4186 hz (C8)
  }
  for (int i = 3000; i < 4000; i++) {

    tone(BUZZER, i);  // Instant beep: 100ms, 4186 hz (C8)
  }
  noTone(BUZZER);
}





void boton_l1() {

  buton_timer = millis();
  buttonState = analogRead(HL);
  if (buttonState > 500) {

    buttonState = 0;
    l_buton_timer = buton_timer;
  } else {
    buttonState = 1;
    if ((buton_timer - l_buton_timer) > 1500) {
      beep_song_3();

      switch (menu_level_1) {
        case 1:
          Setup();
          break;

        case 2:
          Routine();
          break;

        case 3:
          Other();
          break;

        default:
          break;
      }



      l_buton_timer = buton_timer;
    }

  }


  if ((buttonState != lastButtonState) && (buttonState == 1)) {

    switch (menu_level_1) {
        l_buton_timer = buton_timer;
      case 1:
        Serial.println("Setup");

        beep_level1();
        break;

      case 2:
        Serial.println("Routine");

        beep_level2();
        break;

      case 3:
        Serial.println("Other");

        beep_level3();
        break;

      default:
        break;
    }

    delay(100);
  } else {

  }

  lastButtonState = buttonState;

}


void boton_l2() {

  buton_timer = millis();
  buttonState = analogRead(HL);
  if (buttonState > 500) {

    buttonState = 0;
    l_buton_timer = buton_timer;
  } else {
    buttonState = 1;
    if ((buton_timer - l_buton_timer) > 1500) {
      beep_song_3();

      switch (menu_level_2) {
        case 1:
          Calibration();

          break;

        case 2:
          Scanner();

          break;

        case 3:
          Set_Acc();

          break;

        case 4:
          Back();

          break;

        default:
          break;
      }



      l_buton_timer = buton_timer;
    }

  }


  if ((buttonState != lastButtonState) && (buttonState == 1)) {

    switch (menu_level_2) {
      case 1:

        Serial.println("Calibration");
        beep_level1();
        break;

      case 2:
        Serial.println("Scanner");
        beep_level2();
        break;

      case 3:
        Serial.println("Accelerations");

        beep_level3();
        break;

      case 4:
        Serial.println("Back");

        beep_back();
        break;

      default:
        break;
    }

    delay(100);
  } else {

  }

  lastButtonState = buttonState;

}
