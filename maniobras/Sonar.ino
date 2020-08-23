void Check_Sonar_Sensors() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, LOW);

 if (Sonar_2_Activate == 1) distance2 = PingSonarX(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
 if (Sonar_1_Activate == 1) distance1 = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 1, 0);         //SONAR1
 if (Sonar_3_Activate == 1) distance3 = PingSonarX(trigPin3, echoPin3, 3, 3, 3, 2, 0);         //SONAR3

 }
  


/* SONAR Function
************************************************************************************/

int PingSonarX(int trigPinX, int echoPinX, int distanceX, long durationX, int sonarX, int LCDRow, int LCDColumn) {
  pinMode(trigPinX, OUTPUT);
  pinMode(echoPinX, INPUT);
  digitalWrite(trigPinX, HIGH);
  digitalWrite(trigPinX, LOW);
  delayMicroseconds(10);

  durationX = pulseIn(echoPinX, HIGH);
  distanceX = durationX * 0.034 / 2;
  delay(5);

  if (distanceX == 0) {
    distanceX = 999;
    Serial.print(F("S"));
    Serial.print(sonarX);
    Serial.print(F(":"));
    Serial.print(F("NP!"));
    Serial.print(F("|"));
  }

  Serial.print(F("S"));
  Serial.print(sonarX);
  Serial.print(F(":"));
  Serial.print(distanceX);
  Serial.print(F("cm"));
  Serial.print(F("/"));

  if (distanceX <= maxdistancesonar ) {
    
    if (sonarX == 1) {
        Sonar_Hit_1_Total = (Sonar_Hit_1_Total + 1);
        Serial.print(Sonar_Hit_1_Total);
        }
      if (sonarX == 2) {
        Sonar_Hit_2_Total = (Sonar_Hit_2_Total + 1);
        Serial.print(Sonar_Hit_2_Total);
        }
      if (sonarX == 3) {
        Sonar_Hit_3_Total = (Sonar_Hit_3_Total + 1);
        Serial.print(Sonar_Hit_3_Total);
        }      
    if ( (Sonar_Hit_1_Total == Max_Sonar_Hit) || (Sonar_Hit_2_Total == Max_Sonar_Hit) || (Sonar_Hit_3_Total == Max_Sonar_Hit) ) {
      Sonar_Hit = 1;  
      Serial.println("");
      Serial.println("Sonar Hit Detected");
      }
    
    }

  if (distanceX > maxdistancesonar) {
      if (sonarX == 1) {
        Sonar_Hit_1_Total = 0;
        Serial.print(Sonar_Hit_1_Total);
        }
      if (sonarX == 2) {
        Sonar_Hit_2_Total = 0;
        Serial.print(Sonar_Hit_2_Total);
        }
      if (sonarX == 3) {
        Sonar_Hit_3_Total = 0;
        Serial.print(Sonar_Hit_3_Total);
        }   
    }
   

  return distanceX;
  return sonarX;
}
