#include "pitches.h"


#define VRX_PIN  A4 // Arduino pin connected to VRX pin
#define VRY_PIN  A5 // Arduino pin connected to VRY pin

int xValue; // To store value of the X axis
int yValue; // To store value of the Y axis


bool orderArray[] = {0,0,0};
bool healthArray[] = {0,0,0};
int programState = 0;
int Score = 0;
int Health = 3; 


long buttonMillis;
const long intervalButton = 3000; //How long to hold the button



bool HoldAccess = 0;
//bool NeverPressed = 0;




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);

  pinMode(2, OUTPUT);

  pinMode(9, INPUT);

}

// the loop function runs over and over again forever
void loop() 
{
  int MyTime = millis();


  //Press(MyTime, 5000, 8000, digitalRead(9), 0);

  //Hold(MyTime, 3000, 15000, digitalRead(9), 1, 7000);

  JoyStick(MyTime, 2000, 5000, 2);

}




void Press(int Time, int minT, int maxT, bool button, int INDEX)
{
  if(orderArray[INDEX] == 0)
  {
    if((button == HIGH) && ((Time >= minT) && (Time <= maxT)))
    {
      digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)


      Score++;
      orderArray[INDEX] = 1; //Locking this press for next loop;
      healthArray[INDEX] = 1; // Telling code the buttin was pressed in the window. Basically don't lose health  


      tone(2, NOTE_D5, 1000);
      //noTone(8);
    }
    
    if(Time > maxT)
    {
      if(healthArray[INDEX] == 0 && orderArray[INDEX] == 0)
      {
        Health--;

        tone(2, NOTE_G3, 1000); //Error Noise
        //noTone(2);
      }

      orderArray[INDEX] = 1; //Locking this press for next loop;
      healthArray[INDEX] == 1;
    }
  }
}




void Hold(int Time, int minT, int maxT, bool button, int INDEX, long holdLength)
{
  if((button == HIGH) && ((Time >= minT) && (Time <= maxT)) && orderArray[INDEX] == 0)
  {
    HoldAccess = 1;
  }

  unsigned long currentMillis = Time;
  
  if(HoldAccess == 1)
  {
    orderArray[INDEX] = 1;


    int timeHeld;
    bool pressed ;

    if(button == HIGH && programState == 0)
    {
      buttonMillis = currentMillis;
      programState = 1;
    }
    else if(programState == 1 && button == LOW)
    {
      timeHeld = currentMillis - buttonMillis;
      pressed = 1;
      programState = 2; //reset
    }



    if(currentMillis - buttonMillis > holdLength && programState == 1)
    {
      programState = 0; //Resetting states for next time

      Score += holdLength/1000; // Incrementing score. Each second held is a point
      HoldAccess = 0; //Closing the acces for this hold section

      tone(2, NOTE_DS8, 1000);
      //noTone(8);
    }
    else if(programState == 2 && timeHeld > 0)
    {

      programState = 0; //Resetting states for next time

      orderArray[INDEX] == 1; // marking this note as done
      digitalWrite(8, HIGH); // led on for testing

      Score += holdLength/1000; // Incrementing score. Each second held is a point
      HoldAccess = 0; //Closing the acces for this hold section

      tone(2, NOTE_C7, 1000);
      //noTone(2);

      pressed = 0;
      timeHeld = 0;
      
    }
  }

  if((Time > maxT) && orderArray[INDEX] == 0)
  {
    if(healthArray[INDEX] == 0 && orderArray[INDEX] == 0)
    {
      Health--;

      

      tone(2, NOTE_G3, 1000); //Error Noise
      //noTone(2);
    }

    orderArray[INDEX] = 1; //Locking this press for next loop;
  }
}


void JoyStick(int Time, int minT, int maxT, int INDEX) {

  // read analog X and Y analog values
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);


  if(orderArray[INDEX] == 0)
  {
    //print data to Serial Monitor on Arduino IDE
    if( ((xValue < 400 || xValue > 600) || (yValue < 400  || yValue > 600))  &&  ((Time >= minT) && (Time <= maxT)))
    {
      digitalWrite(8, HIGH);
      orderArray[INDEX] = 1;
      Score++; // Incrementing score

      tone(2, NOTE_B5, 1000);
      noTone(8);
    }


    if(Time > maxT)
    {
      if(healthArray[INDEX] == 0 && orderArray[INDEX] == 0)
      {
        Health--;

        tone(2, NOTE_G3, 1000); //Error Noise
        //noTone(2);
      }

      orderArray[INDEX] = 1; //Locking this press for next loop;
      healthArray[INDEX] = 1;
    }
  }
}