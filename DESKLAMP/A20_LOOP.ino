void loop() { 

if(settingMode && switchON){
  whiteBalance += encoder->getValue() * STEP_MULTIPLIER;
  whiteBalance = constrain(whiteBalance, 0 - BASE, BASE);  
  if (whiteBalance != last_whiteBalance) {
    last_whiteBalance = whiteBalance; 
    setBrightness(brightnessValue, whiteBalance, switchON);  
   }             
}

else {  
  brightnessValue += encoder->getValue() * STEP_MULTIPLIER;
  brightnessValue = constrain(brightnessValue, 0, 255);
  if (brightnessValue != last_brightnessValue) {
    switchON = true; //if OFF and turn, switch On
    last_brightnessValue = brightnessValue; 
    setBrightness(brightnessValue, whiteBalance, switchON);
   }       
}  
  
ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    switch (b) {
      case ClickEncoder::Clicked:
            switchON = !switchON;
            Serial.print("SWITCH : ");
            Serial.println(switchON);
            setBrightness(brightnessValue, whiteBalance, switchON);              
      break;
      case ClickEncoder::DoubleClicked:
          settingMode = !settingMode;
          if(settingMode){            
            Serial.println(F("entering setting mode")); // Blink 2X  Entering setting mode
            blinkLed(2, 300, COLDPIN);
          }
          else{
            Serial.println(F("exit setting mode")); // Blink 3X Exit setting mode
            blinkLed(3, 200, WARMPIN);
          }      

        break;
        case ClickEncoder::Released:
          if(settingMode){
            /* SAVE SETTINGS*/
          }
          else {
            //reset values
            Serial.println(F("RESET"));            
          }    
        break;
    }
  }    
}
