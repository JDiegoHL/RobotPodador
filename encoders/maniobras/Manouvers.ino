void Manouver_Mow_The_Grass() {

    Motor_Action_Spin_Blades();
    SetPins_ToGoForwards();
                     
    Serial.print(F("C-Lock:OFF"));
    Serial.print("|");
    Print_LCD_Mowing();
    Get_Compass_Reading();
    Motor_Action_Go_Full_Speed();
    Compass_Heading_Locked = 0;                           
  
    if (Compass_Heading_Hold_Enabled == 0) {
        Serial.print(F("C-Lock:OFF"));
        Serial.print("|");
//        Print_LCD_Compass_Mowing();
        Motor_Action_Go_Full_Speed();
        Compass_Heading_Locked = 0;
        }
    if (Compass_Heading_Hold_Enabled == 1)  {
        Get_Compass_Reading();                            
        Heading_Lock = Heading;                           
        Compass_Heading_Locked = 1;                       
        }

      if (Compass_Heading_Locked == 0) {
        lcd.setCursor(0, 1);
        lcd.print("Mowing..        ");
        Serial.print(F("C-Lock:OFF"));
        Serial.print("|");
        Motor_Action_Go_Full_Speed();
        }
      if (Compass_Heading_Locked == 1) {            
        Get_Compass_Reading(); 
        //Calculate_Compass_Wheel_Compensation();
//        Motor_Action_Dynamic_PWM_Steering();              
        //Print_LCD_Compass_Mowing();
        Serial.print(F("C-Lock:ON_"));
        Serial.print("|");
        }
}

void Manouver_Exit_From_Docking_Station() {
    lcd.clear();
    lcd.print("Exiting Garage");
    delay(2000);
    SetPins_ToGoBackwards();                    // Prepare motors to go Backwards
    Motor_Action_GoFullSpeed_Out_Garage();            // Move Backwards
    delay (7000);                               // Backwards time
    Motor_Action_Stop_Motors;                          // Stop
    SetPins_ToTurnLeft();                       // Prepare motors to turn left
    Motor_Action_Turn_Speed();                         // Turn
    delay(1000);                                 // Turn time
    Motor_Action_Stop_Motors;                          // Stop
    SetPins_ToGoBackwards();                    // Set again to go backwards
    Motor_Action_Go_Full_Speed();                       // Move Backwards
    delay (500);                               // Backwards Time
    SetPins_ToTurnLeft();                       // Set to go left             
    Motor_Action_Turn_Speed();                         // Turn
    delay(200);                                 // Turning time
    Motor_Action_Stop_Motors();                          // Stop
    SetPins_ToGoForwards();                     // Set to go forwards
    Motor_Action_Stop_Motors(); 
    lcd.clear();                                // Clears the LCD display
    lcd.print("Garage Clear");                  // Prints to the LCD screen
    Motor_Action_Stop_Motors; 
    delay(500);
    lcd.clear();
}

void Manouver_Turn_Around_Sonar() {
  Motor_Action_Stop_Motors(); 
  delay(500);
  SetPins_ToGoBackwards();
  Motor_Action_Go_Full_Speed();
  delay(Mower_Reverse_Delay);
  Motor_Action_Stop_Motors(); 

  if ( distance1 < maxdistancesonar ||  distance2 < maxdistancesonar ) {
      SetPins_ToTurnRight();
      Motor_Action_Turn_Speed();
      delay(Mower_Turn_Delay_Right);
      }

  if (distance3 < maxdistancesonar) {
      SetPins_ToTurnLeft();
      Motor_Action_Turn_Speed();
      delay(Mower_Turn_Delay_Left);
      }
  
  Motor_Action_Stop_Motors();
  Sonar_Hit = 0;
//  Loop_Cycle_Mowing = 0;
  
}
