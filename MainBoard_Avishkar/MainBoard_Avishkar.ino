void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(8,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  Serial.begin(9600);
}


int inputRead(int d0,int d1,int d2,int d3)
{
  int input;
  if((d3==0)&&(d2==0)&&(d1==0)&&(d0==1))
    input=1;
  else if((d3==0)&&(d2==0)&&(d1==1)&&(d0==0))
    input=2;
  else if((d3==0)&&(d2==0)&&(d1==1)&&(d0==1))
    input=3;
  else if((d3==0)&&(d2==1)&&(d1==0)&&(d0==0))
    input=4;
  else if((d3==0)&&(d2==1)&&(d1==0)&&(d0==1))
    input=5;
  else if((d3==0)&&(d2==1)&&(d1==1)&&(d0==0))
    input=6;
  else if((d3==0)&&(d2==1)&&(d1==1)&&(d0==1))
    input=7;
  else if((d3==1)&&(d2==0)&&(d1==0)&&(d0==0))
    input=8;
  else if((d3==1)&&(d2==0)&&(d1==0)&&(d0==1))
    input=9;
  else 
    input=-1;
  return input;
}

int combination(int first, int second)
{
  if((first==3)&&(second==3))
    return 1;
  if((first==3)&&(second==6))
    return 2;
  if((first==3)&&(second==9))
    return 3;
  if((first==6)&&(second==3))
    return 4;
  if((first==6)&&(second==6))
    return 5;
  if((first==6)&&(second==9))
    return 6;
  if((first==9)&&(second==3))
    return 7;
  if((first==9)&&(second==6))
    return 8;
  if((first==9)&&(second==9))
    return 9;
 }

int LightsON()
{
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  return 1;
}

int LightsOFF()
{
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  return 0;
}

int FansON()
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  return 1;
}

int FansOFF()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  return 0;
}

int curtainsON()
{
  digitalWrite(22,HIGH);
  digitalWrite(23,LOW);
  delay(14500);
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
  return 1;
}

int curtainsOFF()
{
  digitalWrite(22,LOW);
  digitalWrite(23,HIGH);
  delay(14500);
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
  return 0;
}

void lockCLOSE()
{
  digitalWrite(24,LOW);
  digitalWrite(25,HIGH);
  delay(19000);
  digitalWrite(24,LOW);
  digitalWrite(25,LOW); 
}

void lockOPEN()
{
  digitalWrite(24,HIGH);
  digitalWrite(25,LOW);
  delay(19000);
  digitalWrite(24,LOW);
  digitalWrite(25,LOW);
}

void HandleDOWN()
{
  digitalWrite(26,HIGH);
  digitalWrite(27,LOW);
  delay(18000);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);  
}

void HandleUP()
{
  digitalWrite(26,LOW);
  digitalWrite(27,HIGH);
  delay(9340);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);  
}

void DoorOPEN()
{
  analogWrite(A0,255);
  analogWrite(A1,0);
  delay(10000);
  analogWrite(A0,0);
  analogWrite(A1,0);    
}

void DoorCLOSE()
{
  analogWrite(A0,0);
  analogWrite(A1,255);
  delay(15000);
  analogWrite(A0,0);
  analogWrite(A1,0);
}

void loop() {
  int d0,d1,d2,d3,input1,input2,input,lightStatus,fanStatus,curtainStatus,std,a0;
  lightStatus=LightsOFF();
  fanStatus=FansOFF();
  curtainStatus=1;
    while(1)
    { 
      std=digitalRead(8);
      if(std==1)
     {    
     d0=digitalRead(2);
     d1=digitalRead(3);
     d2=digitalRead(4);
     d3=digitalRead(5);
     input1=inputRead(d0,d1,d2,d3);
     delay(1000);     
     d0=digitalRead(2);
     d1=digitalRead(3);
     d2=digitalRead(4);
     d3=digitalRead(5);
     input2=inputRead(d0,d1,d2,d3);
     input=combination(input1,input2);
     Serial.println(input);
     switch(input)
     {
       case 1:
       {
         if(lightStatus==0)
          lightStatus=LightsON();
         else
          lightStatus=LightsOFF();
          break;
       }
       case 2:
       {
        lightStatus=LightsOFF();
        break;
       }
       case 3:
       {
        if(fanStatus==0)
          fanStatus=FansON();
        else
          fanStatus=FansOFF();
        break;
       }
       case 4:
       {
        if(curtainStatus==0)
          curtainStatus=curtainsON();
        else
          curtainStatus=curtainsOFF();
          break;
       }
       case 5:
       {
         lockCLOSE();
         break;
       }
       case 6:
       {
          lockOPEN();
          break;
       }
       case 7:
       {
          HandleDOWN();
          delay(1000);
          DoorOPEN();
          delay(1000);
          HandleUP();
          break;
       }
       case 8:
       {
          HandleDOWN();
          delay(1000);
          DoorCLOSE();
          delay(100);
          HandleUP();
          break;
       }
      }
      delay(1000);
    }
   }
 }

