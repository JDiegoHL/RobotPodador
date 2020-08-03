

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
