#include <HID.h>

#include <Arduino.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#include <DFRobot_QMC5883.h>
DFRobot_QMC5883 compass;

//Encoders
const byte encoder0pinAR = 2;
const byte encoder0pinBR = 3;

const byte encoder0pinAL = 18;
const byte encoder0pinBL = 19;
byte encoder0PinALastR;
byte encoder0PinALastL;
int durationR;
int durationL;

int durationAnt;
int Deltaduration;

boolean DirectionR;
boolean DirectionL;

//

// 

#define echoPin1 34   //S1               
#define trigPin1 35
#define echoPin2 36   //S2 
#define trigPin2 37
#define echoPin3 38   //S3
#define trigPin3 39

// 

//Motor A
#define ENAPin 7                
#define IN1Pin 6                
#define IN2Pin 5
//Motor B
#define ENBPin 8//2                
#define IN3Pin 10//4                
#define IN4Pin 9//3

//Motor Blades
#define RPWM 8
#define L_EN 9
#define R_EN 10

//Relay Switch
#define Relay_Motors 24        

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

  int I=1;                                
 //
  float Compass_Heading_Degrees;
  float Heading;
  bool  Compass_Heading_Locked = 0;
  float Heading_Lock;
  int   Heading_Upper_Limit_Compass;
  int   Heading_Lower_Limit_Compass;
  //
  
  bool Cutting_Blades_Activate    = 1;      
 //                     
  bool Compass_Activate               = 1;                      
  bool Compass_Heading_Hold_Enabled   = 0;                      
  int  Home_Wire_Compass_Heading      = 120;                    
  int  CPower                         = 120;                    

 //
  bool Sonar_1_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 1
  bool Sonar_2_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 2
  bool Sonar_3_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 3
  int  Max_Sonar_Hit              = 3;                          
  long maxdistancesonar           = 30;
                        
  //Wheel Motor Setup
  byte Max_Cycles                 = 150;
  byte PWM_MaxSpeed_LH            = 100;                        
  byte PWM_MaxSpeed_RH            = 155;                        


  int Mower_Turn_Delay_Left       = 1800;                       
  int Mower_Turn_Delay_Right      = 1500;                       
  int Mower_Reverse_Delay         = 1500;                       
  
  byte PWM_Blade_Speed            = 245;
  //

void setup() {
  Serial.begin(115200);
  //Serial2.begin(1200);
  EncoderInit();
  Setup_Relays();
  Setup_Motor_Pins();
  Setup_Motor_Pins();
  Setup_Compass();
  }

void loop() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("OPCIONES");
  //lcd.setCursor(0,1);
  //Manouver_Exit_From_Docking_Station();
  
//Test_Wheel_Motors();
Check_Sonar_Sensors();
if ((Sonar_Hit == 1))        Manouver_Turn_Around_Sonar();
Encoder_Sensor();
Serial.println(); 
  
}  // End Loop

  
