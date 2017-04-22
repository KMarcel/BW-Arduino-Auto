/****************************************************************************
 Titel	:   Schrittmotoren Library für das Projekt Arduino Auto
 Autor:    Marcel Kühl <Marcel.Kuehl@web.de>  http://github.com/KMarcel
 Datei:	    Schrittmotor.cpp
 Software:  Arduino IDE
 Beschreibung
       In dieser Schrittmotor.cpp Datei sind alle wichtigen Funktionen
	   zum Ansteuern beider Schrittmotoren vorhanden
       
*****************************************************************************/
#include <Schrittmotor.h>
Schrittmotor::Schrittmotor(int *PinOuts)
{
	
for(int i = 0; i<=7; i++)
{
   this->PinOuts[i] = PinOuts[i];   
   this->Standart[i] = PinOuts[i];
   pinMode(PinOuts[i], OUTPUT);
}
	
   this->Speed = 0;
}
void Schrittmotor::setNewSpeed(int speed)
{
	this->Speed = speed;
}
void Schrittmotor::Update()
{
	
  for(int i = 0; i<=7; i++)
  {
     this->PinOuts[i] = this->Standart[i];
  }
	
}
void Schrittmotor::Schritte(Stepper Schritte, int Pin1, int Pin2, int Pin3, int Pin4)
{

	switch(Schritte)
	{
		case Schritt_1:
			digitalWrite(Pin1, HIGH);
			digitalWrite(Pin2, LOW);
			digitalWrite(Pin3, HIGH);
			digitalWrite(Pin4, LOW);
		break;
		
		case Schritt_2:
			digitalWrite(Pin1, LOW);
			digitalWrite(Pin2, HIGH);
			digitalWrite(Pin3, HIGH);
			digitalWrite(Pin4, LOW);		
		break;
		
		case Schritt_3:
			digitalWrite(Pin1, LOW);
			digitalWrite(Pin2, HIGH);
			digitalWrite(Pin3, LOW);
			digitalWrite(Pin4, HIGH);		
		break;
		case Schritt_4:
			digitalWrite(Pin1, HIGH);
			digitalWrite(Pin2, LOW);
			digitalWrite(Pin3, LOW);
			digitalWrite(Pin4, HIGH);
		break;
	}
}
void Schrittmotor::Forwards()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[0],this->PinOuts[1],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[4],this->PinOuts[5],this->PinOuts[6],this->PinOuts[7]);
		delay(this->Speed);		
	}
}
void Schrittmotor::Backwards()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[1],this->PinOuts[0],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[5],this->PinOuts[4],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
	
}
void Schrittmotor::Left()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[0],this->PinOuts[1],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[5],this->PinOuts[4],this->PinOuts[6],this->PinOuts[7]);
		delay(this->Speed);		
	}
}
void Schrittmotor::Right()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[1],this->PinOuts[0],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[4],this->PinOuts[5],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
}