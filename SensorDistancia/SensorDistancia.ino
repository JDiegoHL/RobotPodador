
#include <Arduino.h>
#include <Wire.h>

//Motor A
#define ENAPin 7                
#define IN1Pin 6                
#define IN2Pin 5
//Motor B
#define ENBPin 2                
#define IN3Pin 4                
#define IN4Pin 3

//Motor Blades
#define RPWM 8
#define L_EN 9
#define R_EN 10

//Relay Switch
#define Relay_Motors 24        

#define echoPin1 34   //S1               
#define trigPin1 35
#define echoPin2 36   //S2 
#define trigPin2 37
#define echoPin3 38   //S3
#define trigPin3 39

  int I=1;                                
  bool Cutting_Blades_Activate    = 1;                           
 

   byte PWM_Blade_Speed            = 245;                        
  
  int Max_Tracking_Turn_Right    = 150;                         
  int Max_Tracking_Turn_Left     = 150;                         
  
  //Wheel Motor Setup
  byte Max_Cycles                 = 150;
  byte PWM_MaxSpeed_LH            = 100;                        
  byte PWM_MaxSpeed_RH            = 155;                        

  long duration1 = 0;                     
  long duration2 = 0;
  long duration3 = 0;

  int distance1 = 999;                    
  int distance2 = 999;
  int distance3 = 999;

  int distance_blockage;     

  int Sonar_Hit_1_Total;
  int Sonar_Hit_2_Total;
  int Sonar_Hit_3_Total;
  bool Sonar_Hit_Any_Total;
  bool Sonar_Hit_1 = 0;
  bool Sonar_Hit_2 = 0;
  bool Sonar_Hit_3 = 0;
  bool Sonar_Hit   = 0;

  bool Sonar_1_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 1
  bool Sonar_2_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 2
  bool Sonar_3_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 3
  int  Max_Sonar_Hit              = 3;                          
  long maxdistancesonar           = 30;

  int Mower_Turn_Delay_Left       = 1800;                       
  int Mower_Turn_Delay_Right      = 1500;                       
  int Mower_Reverse_Delay         = 1500;                       

void setup() {
  Serial.begin(115200);
  Setup_Relays();
  Setup_Motor_Pins();
  }

void loop() {
//Test_Wheel_Motors();
Check_Sonar_Sensors();
if ((Sonar_Hit == 1))        Manouver_Turn_Around_Sonar();
Serial.println(); 
  
}  // End Loop

  
