void setup() {
  Serial.begin(9600);
  encoder = new ClickEncoder(ENCODER_A, ENCODER_B, ENCODER_BTN, 4);
  encoder->setAccelerationEnabled(true);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  Serial.println(F("NINJA DESK LAMP"));
  Serial.print("SWITCH : ");
  Serial.println(switchON);
  /*
  if(digitalRead(ENCODER_BTN) == 0) {
    Serial.println(F("DEBUG MODE"));
  }*/
  Serial.println( );  
}

