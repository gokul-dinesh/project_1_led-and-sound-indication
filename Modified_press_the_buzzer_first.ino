// Atlernative shorter code 

boolean  ResetStatus=false;
boolean Bclick=LOW;

boolean b1state,b2state,b3state,b4state,b5state = 0;


void setup()
{
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,INPUT);
  pinMode(6,OUTPUT);
  pinMode(9,INPUT);
  pinMode(8,OUTPUT);
  pinMode(11,INPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);

  Serial.begin(9600);
}

void buzzer()
{			
  digitalWrite(12,HIGH);
  tone(12,800,3000);
  digitalWrite(12,LOW);
}

void button_state(int x, int y)
{
  digitalWrite(x,HIGH);
  for(int i=x;i<=11;i++)
  {
    if(i==x){digitalWrite(i,HIGH);}
    if(i==y){continue;}
    if(i!=x && i!=7){digitalWrite(i,LOW);}
  }
  buzzer();
  delay(3000);
  while(digitalRead(3));
  Bclick =HIGH;
}


void loop()
{ // Reading button states 
  boolean b1state = digitalRead(3);
  boolean b2state = digitalRead(5);
  boolean b3state = digitalRead(7);
  boolean b4state = digitalRead(9);
  boolean b5state = digitalRead(11);

  // If the Reset button state is HIGH
  if (b1state == 1)
  {
    ResetStatus = true;
    digitalWrite(2,HIGH);
    delay(20);

    // Setting all the LEDs to LOW  (RESET)
    for(int i=2;i<=10; i+=2){digitalWrite(i,LOW);}   
    Bclick = LOW;
  }

  if (b1state == 0)
  {
    ResetStatus = false;
    digitalWrite(2,LOW); 
  }


  // If Reset buttons is not pressed then;
  if(ResetStatus == false )
  {
    b2state = digitalRead(5);
    b3state = digitalRead(7);
    b4state = digitalRead(9);
    b5state = digitalRead(11);

    // IF Person-1 clicks the Button
    if(b2state == 1 && Bclick == LOW){button_state(4,5);}

    // IF Person-2 clicks the Button
    if(b3state == 1 && Bclick == LOW){button_state(6,7);}

    // IF Person-3 clicks the Button
    if(b4state == 1 && Bclick == LOW){button_state(8,9);}

    // IF Person-4 clicks the Button  
    if(b5state == 1 && Bclick == LOW){button_state(10,11);}

  }

  Serial.flush();
}
