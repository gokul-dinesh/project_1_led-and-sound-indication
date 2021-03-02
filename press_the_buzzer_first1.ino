// Code done by Tejas Rote 
boolean  ResetStatus=false;
boolean Bclick=LOW;

boolean b1state = 0;
boolean b2state = 0;
boolean b3state = 0;
boolean b4state = 0;
boolean b5state = 0;


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
  pinMode(10,INPUT);
  pinMode(12,OUTPUT);

  Serial.begin(9600);
}

void buzzer()
{			
  digitalWrite(12,HIGH);

  tone(12,800,3000);
  digitalWrite(12,LOW);

}

void loop()
{

  // Reading button states 
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
    delay(200);

    // Setting all the LEDs to LOW  (RESET)
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    Bclick = LOW;

  }
  delay(500);

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
    if(b2state == 1 && Bclick == LOW)
    {
      // Setting the state of the LEDs
      digitalWrite(4,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
      digitalWrite(10,LOW);

      // Setting the state of the other buttons
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(11,LOW);

      // Activating the buzzer 
      buzzer();   
      // Wait till buzzer is off
      delay(3000);
      // Keep reading the ZReset button state 
      while(digitalRead(3));
      // Updating the variable condition for buttons 
      Bclick = HIGH;
    }


    // IF Person-2 clicks the Button
    if(b3state == 1 && Bclick == LOW)
    {
      digitalWrite(6,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(8,LOW);
      digitalWrite(10,LOW);

      digitalWrite(5,LOW);
      digitalWrite(9,LOW);
      digitalWrite(11,LOW);
      buzzer();
      delay(3000);
      while(digitalRead(3));

      Bclick = HIGH;
    }


    // IF Person-3 clicks the Button
    if(b4state == 1 && Bclick == LOW)
    {
      digitalWrite(8,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(4,LOW);
      digitalWrite(10,LOW);

      digitalWrite(7,LOW);
      digitalWrite(5,LOW);
      digitalWrite(11,LOW);
      buzzer();
      delay(3000);
      while(digitalRead(3));

      Bclick = HIGH;
    }



    // IF Person-4 clicks the Button  
    if(b5state == 1 && Bclick == LOW)
    {
      digitalWrite(10,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
      digitalWrite(4,LOW);

      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(5,LOW);

      buzzer();
      delay(3000);
      while(digitalRead(3));

      Bclick = HIGH;

    }

  }

  Serial.flush();
}