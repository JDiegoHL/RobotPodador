
void Test_Relay() {
  
  digitalWrite(Relay_Motors, HIGH);
  Serial.println("Relay OFF");

  digitalWrite(Relay_Motors, LOW);
  Serial.println("Relay ON");
}



void Test_Wheel_Motors() {

  digitalWrite(Relay_Motors, LOW);
  delay(200);
  if (I == 1) {

  SetPins_ToTurnLeft();
  Motor_Action_Go_Full_Speed();
  delay(1000);
  Motor_Action_Stop_Motors();
  delay(1000);

  SetPins_ToTurnRight();
  Motor_Action_Go_Full_Speed();
  delay(2000);
  Motor_Action_Stop_Motors();
  delay(1000);
  
  SetPins_ToGoForwards();
  Motor_Action_Go_Full_Speed();
  delay(1000);
  Motor_Action_Stop_Motors(); 
  delay(1000);
  
  SetPins_ToGoBackwards();   
  Motor_Action_Go_Full_Speed();
  delay(1000);
  Motor_Action_Stop_Motors();  
  delay(1000);

  I = 2;
  }
  digitalWrite(Relay_Motors, HIGH);
  delay(200);
}     



void Test_Mower_Blade_Motor() {

  digitalWrite(Relay_Motors, LOW);
  delay(200);
  delay(1000);
  Serial.println("Blades ON");
  Motor_Action_Spin_Blades();
  delay(7000);

  
  Motor_Action_Stop_Spin_Blades();
  delay(2000);
  digitalWrite(Relay_Motors, HIGH);
  delay(200);

  }

  
