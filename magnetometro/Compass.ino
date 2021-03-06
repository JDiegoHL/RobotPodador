void Get_Compass_Reading() {

  Vector norm = compass.readNormalize();
  delay(5);
  Heading = atan2(norm.YAxis, norm.XAxis);                        // Calculate heading

  // Set declination angle. Find your location declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative,
  float Declination_Angle = (2.0 + (19.0 / 60.0)) / (180 / PI);   // Bad Krozingen is 2° 19'
  Heading += Declination_Angle;

  if (Heading < 0) {                                              // Correct for heading < 0deg and heading > 360deg
    Heading += 2 * PI;
    }
  if (Heading > 2 * PI) {
    Heading -= 2 * PI;
    }

  Compass_Heading_Degrees = Heading * 180 / M_PI;                 // Convert to degrees
  Serial.print(F("Comp H:"));
  Serial.print(Heading);
  Serial.print(F(" D:"));
  Serial.print(Compass_Heading_Degrees);
  Serial.print("|");
  delay(5);
}


void Compass_Turn_Mower_To_Home_Direction() {
    Motor_Action_Stop_Motors;
    delay(1000);
    //Print_LCD_Compass_Home();
    delay(2000);
    Heading_Lower_Limit_Compass = Home_Wire_Compass_Heading - 8;
    Heading_Upper_Limit_Compass = Home_Wire_Compass_Heading + 8;
    Serial.println(F("********************************"));
    Serial.print(F("Home Heading Target : "));
    Serial.println(Home_Wire_Compass_Heading);
    Serial.print(F("Tolerance : "));
    Serial.print(Heading_Lower_Limit_Compass);
    Serial.print(F("  :  "));
    Serial.println(Heading_Upper_Limit_Compass);
    Serial.println(F("********************************"));
    Print_LCD_Heading_for_Home();
    delay(2000);
    lcd.clear();
    Get_Compass_Reading();
    SetPins_ToTurnLeft(); 
    Serial.print(F("Compass Heading Now : "));
    Serial.println(Compass_Heading_Degrees);
    Serial.println(F("********************************"));
    delay(100);
    lcd.print(Compass_Heading_Degrees);
    // This spins the mower a little to ensure a true compass reading is being read (calibration).
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(500);    
    Motor_Action_Stop_Motors();
    Get_Compass_Reading();
    lcd.clear();
    lcd.print(Compass_Heading_Degrees);
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    delay(100);
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(2000);  
    Motor_Action_Stop_Motors();
    Get_Compass_Reading();
    delay(500);
    lcd.clear();
    lcd.print("Compass Set");
    Motor_Action_Stop_Motors();
    delay(2000);
    Turn_To_Compass_Heading();
}



void Turn_To_Compass_Heading()  {
    // Step turns the mower to the left while the heading is outside the home tolerance
    // Once the heading is found. the mower stops and can then activate the find wire function
    SetPins_ToTurnLeft(); 
    while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass)) {    
        Serial.println(F("Turning to Home"));
        Get_Compass_Reading();
        lcd.setCursor(0,0);
        lcd.print("Target: ");
        lcd.print( ((Heading_Lower_Limit_Compass - Heading_Lower_Limit_Compass) / 2 ) + Heading_Lower_Limit_Compass);
        lcd.setCursor(0,1);
        lcd.print("Now:");
        lcd.setCursor(0,4);
        lcd.print("   ");
        lcd.print(Compass_Heading_Degrees);
        Serial.print(F("Compass Heading Now:"));
        Serial.print(Compass_Heading_Degrees);
        Serial.print("|");
        Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
        }
    Motor_Action_Stop_Motors();
    SetPins_ToGoForwards();
    lcd.print("Found");
    delay(1000);
    lcd.clear();
 }

void Display_Compass_Current_Heading_on_LCD() {
      lcd.setCursor(5, 1);
      lcd.print("    ");
      lcd.print(Compass_Heading_Degrees);
      delay(10);
}



//
