void EncoderInit()
{
  Direction = true;//default -> Forward  
  pinMode(encoder0pinB,INPUT);  
  attachInterrupt(0, wheelSpeed, CHANGE);//int.0 
}
void Setup_Compass() {
  if (Compass_Activate == 1) {
  /*Setup Compass
  *************************************************************************/
  lcd.clear();
  lcd.print("Compass  ");
  lcd.setCursor(0, 1);
  lcd.print("Setup");
  while (!compass.begin())
  {
    Serial.println(F("Could not find a valid QMC5883 sensor, check wiring!"));
    delay(500);
  }

  if (compass.isHMC()) {
    Serial.println(F("Initialize HMC5883"));
    compass.setRange(HMC5883L_RANGE_1_3GA);
    compass.setMeasurementMode(HMC5883L_CONTINOUS);
    compass.setDataRate(HMC5883L_DATARATE_15HZ);
    compass.setSamples(HMC5883L_SAMPLES_8);
  }
  else if (compass.isQMC()) {
    Serial.println(F("Initialize QMC5883"));
    compass.setRange(QMC5883_RANGE_2GA);
    compass.setMeasurementMode(QMC5883_CONTINOUS);
    compass.setDataRate(QMC5883_DATARATE_50HZ);
    compass.setSamples(QMC5883_SAMPLES_8);
  }
  lcd.clear();
  lcd.print("Compass Setup ");
  lcd.setCursor(0, 1);
  lcd.print("Done!             ");
  delay(500);
  lcd.clear();
}

if (Compass_Activate == 0) {
  Serial.println(F("Compass Switched off - Select 1 in setup to switch on.")); 
  }
}

void Setup_Relays() {
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  Turn_Off_Relay();
  delay(5);
  }

void Setup_Motor_Pins() {
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);
  }


void  Turn_On_Relay() {
   Serial.print("Relay:ON|");
   digitalWrite(Relay_Motors, LOW);                         
   }

void  Turn_Off_Relay() {
   Serial.print("Relay:Off|");
   digitalWrite(Relay_Motors, HIGH);                        
   }
