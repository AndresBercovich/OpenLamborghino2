
void Init() {

  boton_l1();

}


void StandBy() {

  Serial.println("StandBy");

}

void Setup() {
  Serial.println("Select Setup");


  while (menu_level_1 == 1) {


    boton_l2();
    menu_enc_count();
    wheel_scroll_2();

  }
  Serial.println("Select Setup exit");
}


void Routine() {
  Serial.println("Select Routine");
}

void Calibration() {
  Serial.println("Select Calibration");
}

void Scanner() {
  Serial.println("Select Scanner");
}

void Set_Acc() {
  Serial.println("Select Set Acelerations");
}

void Back() {
  Serial.println("Select Back");
  menu_level_1 == 0;
}

void Other() {
  Serial.println("Select Other");


}
