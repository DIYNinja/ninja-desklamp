void blinkLed(int times, int duration, int pin){
  for (int i=1; i <= times; i++){
      analogWrite(pin, 0);
      delay(duration);
      analogWrite(pin, 128);
      delay(duration);
      analogWrite(pin, 128);      
   }
}


 void setBrightness(int brightnessValue, int whiteBalance, bool switchON){
  if(switchON){    

    /*
    coldValue = brightnessValue * whiteBalance / BASE;  
    warmValue = brightnessValue * (BASE - whiteBalance) / BASE;*/
    coldValue = brightnessValue;
    warmValue = brightnessValue;
    if(whiteBalance < 0) {
      coldValue = brightnessValue - (brightnessValue * abs(whiteBalance) / BASE);    
    }
    if(whiteBalance > 0) {
      warmValue = brightnessValue - (brightnessValue * abs(whiteBalance) / BASE);
     }
    
    
    coldValue = constrain(coldValue, 0, 255);
    warmValue = constrain(warmValue, 0, 255);
    analogWrite(COLDPIN, coldValue);
    analogWrite(WARMPIN, warmValue); 
    
    value_output();        
  }
  else{
    analogWrite(COLDPIN, 0);
    analogWrite(WARMPIN, 0);
  }  
 }

 void value_output (){
  Serial.print(F("MODE : "));
  Serial.print(settingMode);
  Serial.print(F(" BRIGHT : "));
  Serial.print(brightnessValue);  
  Serial.print(F(" BALANCE : "));
  Serial.print(whiteBalance);
  Serial.print(F(" COLD : "));
  Serial.print(coldValue);
   Serial.print(F(" WARM : "));
  Serial.print(warmValue);
  Serial.println(); 
 }
