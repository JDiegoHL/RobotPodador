void Motor_Action_Go_Full_Speed()     {
      analogWrite(ENAPin, PWM_MaxSpeed_RH);                       
      analogWrite(ENBPin, PWM_MaxSpeed_LH);                       
      Serial.print(F("Wheel:FULL|"));
      }

void Motor_Action_GoFullSpeed_Out_Garage()     {
  analogWrite(ENAPin, PWM_MaxSpeed_RH);                                       
  analogWrite(ENBPin, PWM_MaxSpeed_LH);                                       
  Serial.print(F("Wheel:FULL|"));
  }


void SetPins_ToGoForwards()     {                                 
  digitalWrite(IN1Pin, LOW);                                      
  digitalWrite(IN2Pin, HIGH);
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, HIGH);
  Serial.print(F("Wheel:For|"));
  }


void SetPins_ToGoBackwards()      {                               
  digitalWrite(IN1Pin, HIGH);                                     // Motor 1
  digitalWrite(IN2Pin, LOW);
  digitalWrite(IN3Pin, HIGH);                                     // Motor 2
  digitalWrite(IN4Pin, LOW);
  Serial.print(F("Wheel:Rev|"));
  delay(20);
  }


void Motor_Action_Stop_Motors()  {                                
  digitalWrite(ENAPin, 0);
  digitalWrite(IN1Pin, LOW);                                    //Motor 1
  digitalWrite(IN2Pin, LOW);

  digitalWrite(ENBPin, 0);                                      //Motor 2
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, LOW);

  Serial.print(F("Wheel:0FF|"));
}


void SetPins_ToTurnLeft()       {                              
    digitalWrite(IN1Pin, LOW);                                 
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);                                  // Motor 2
    digitalWrite(IN4Pin, LOW);
    Serial.print(F("Wheel:TL_|"));  
    }


void SetPins_ToTurnRight() {                                   
      digitalWrite(IN1Pin, HIGH);                                   // Motor 1
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, LOW);                                    //Motor 2
      digitalWrite(IN4Pin, HIGH);
      Serial.print(F("Wheel:R|"));
      }

void Motor_Action_Turn_Speed() {
      analogWrite(ENAPin, (PWM_MaxSpeed_RH - 0) );                                  
      analogWrite(ENBPin, (PWM_MaxSpeed_LH - 0) );                                  
      }

void Motor_Action_Spin_Blades()  {
  if (Cutting_Blades_Activate == 1) {                                       
    delay(20);
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
    delay(20);
    analogWrite(RPWM, PWM_Blade_Speed);
    delay(20);
    Serial.print("Blades:ON_|");
   }                 

  if (Cutting_Blades_Activate == 0) {                                     
    void StopSpinBlades();
  }
}

void Motor_Action_Stop_Spin_Blades()  {
  delay(20);
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
  delay(20);
  Serial.print("Blades:0FF|");
}
