#include <Schrittmotor.h>

#define Trig 7
#define Echo 6

Schrittmotor Motoren(0, 1, 2, 3, 8, 9, 10, 11);

unsigned long previousMillis = 0;   
int Interval = 60;


int Speed = 2000;
long Messung = 0;
int Ergebnis = 0;
void Setup()
{
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Motoren.setNewSpeed(Speed);
}

void loop()
{  
  if(millis()-previousMillis > Interval)
  {
    digitalWrite(Trig, LOW);
    delaymircoseconds(2);
    digitalWrite(Trig, HIGH);
    delaymircoseconds(10);
    digitalWrite(Trig, LOW);
    Messung = pulseIn(Echo, HIGH);
    Ergebnis = (Messung/2)/27;
    
  }
  
  if(Ergebnis > 30)
  {
    Motoren.Forwards();
  }
  if(Ergebnis < 30)
  {
    Motoren.Left();
  }
}
