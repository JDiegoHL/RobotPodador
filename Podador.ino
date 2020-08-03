#include <Arduino.h>
#include <Wire.h>

//Motor A
#define ENAPin 7                // EN Pins need a digital pin with PWM
#define IN1Pin 6                // IN Pins dont need digital PWM 
#define IN2Pin 5
//Motor B
#define ENBPin 2                // EN Pins need a digital pin with PWM
#define IN3Pin 4                // IN Pins dont need digital PWM
#define IN4Pin 3

//Motor Blades
#define RPWM 8
#define L_EN 9
#define R_EN 10

//Relay Switch
#define Relay_Motors 24        

int I=1;                                
 bool Cutting_Blades_Activate    = 1;                           
 

    byte PWM_Blade_Speed            = 245;                        
  
  int Max_Tracking_Turn_Right    = 150;                         
  int Max_Tracking_Turn_Left     = 150;                         
  
  //Wheel Motor Setup
  byte Max_Cycles                 = 150;
  byte PWM_MaxSpeed_LH            = 100;                        
  byte PWM_MaxSpeed_RH            = 155;                        

                 

void setup() {
  Serial.begin(115200);
  Setup_Relays();
  Setup_Motor_Pins();
  }

void loop() {
Test_Wheel_Motors();

Serial.println(); 
  
}  // End Loop

  
