void Encoder_Sensor()
{
  Serial.print("Pulso: ");
  Serial.print(duration);
  duration = 0;
  delay(100);
  Serial.print("|");
}
// Infornation to be printed to the Mower LCD screen

//


void Print_Mower_Lost() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mower Lost");
  lcd.setCursor(0,1);
  lcd.print("Reset Mower");
  
}

//
//
//

void Print_Recharge_LCD() {
    lcd.setCursor(0,1);
    lcd.print("Recharge Batt");
    }

void Print_LCD_Wire()  {
       lcd.setCursor(0, 1);
       lcd.print("WIRE Detect ");     
    }

void Print_LCD_Mowing() {
       lcd.setCursor(0, 1);
       lcd.print("Mowing..    ");   
     }

//

void Print_LCD_Info_Parked() {
    lcd.setCursor(0,1);
    lcd.print("Parked");
    }

void Print_LCD_Info_Docked() {
    lcd.setCursor(0,1);
    lcd.print("Docked");  
}

//

void Print_Sonar_Hit()  {
    lcd.setCursor(0,1);
    lcd.print("Sonar Object ");  
    }

//

void Print_LCD_Heading_for_Home() {
  lcd.setCursor(0,1);
  lcd.print("Target:");
  lcd.print( ((Heading_Lower_Limit_Compass - Heading_Lower_Limit_Compass) / 2 ) + Heading_Lower_Limit_Compass);
  }




//
