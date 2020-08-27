void wheelSpeedR()
{
  int LstateR = digitalRead(encoder0pinAR);
  //int LstateL = digitalRead(encoder0pinAL);
  if((encoder0PinALastR == LOW) && LstateR==HIGH)
  {
    int valR = digitalRead(encoder0pinBR);
    if(valR == LOW && DirectionR)
    {
      DirectionR = false; //Reverse
    }
    else if(valR == HIGH && !DirectionR)
    {
      DirectionR = true;  //Forward
    }
  }
  /*if((encoder0PinALastL == LOW) && LstateL==HIGH)
  {
    int valL = digitalRead(encoder0pinBL);
    if(valL == LOW && DirectionL)
    {
      DirectionL = false; //Reverse
    }
    else if(valL == HIGH && !DirectionL)
    {
      DirectionL = true;  //Forward
    }
  }*/
  encoder0PinALastR = LstateR;
  //encoder0PinALastL = LstateL;
  
  if(!DirectionR)  durationR++;
  else  durationR--;
  //if(!DirectionL)  durationL++;
  //else  durationL--;
}


void wheelSpeedL()
{
  int LstateL = digitalRead(encoder0pinAL);
  
  if((encoder0PinALastL == LOW) && LstateL==HIGH)
  {
    int valL = digitalRead(encoder0pinBL);
    if(valL == LOW && DirectionL)
    {
      DirectionL = false; //Reverse
    }
    else if(valL == HIGH && !DirectionL)
    {
      DirectionL = true;  //Forward
    }
  }
 
  encoder0PinALastL = LstateL;
  
  if(!DirectionL)  durationL++;
  else  durationL--;
}
/*void R_Encoder(){
 durationAnt=duration;
 Deltaduration=duration-durationAnt;
 if()
  
  }*/
