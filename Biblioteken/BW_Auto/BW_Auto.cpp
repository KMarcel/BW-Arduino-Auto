/****************************************************************************
 Titel	:   BW_Autoen Library für das Projekt Arduino Auto
 Autor:    Marcel Kühl <Marcel.Kuehl@web.de>  http://github.com/KMarcel
 Datei:	    BW_Auto.cpp
 Software:  Arduino IDE
 Beschreibung
       In dieser BW_Auto.cpp Datei sind alle wichtigen Funktionen
	   zum Ansteuern beider BW_Autoen vorhanden
       
*****************************************************************************/
#include <BW_Auto.h>
BW_Auto::BW_Auto(int *PinOuts,int Trig, int Echo, unsigned int interval)
{
	
for(int i = 0; i<=7; i++)
{
   this->PinOuts[i] = PinOuts[i];   
   this->Standart[i] = PinOuts[i];
   pinMode(PinOuts[i], OUTPUT);
}
	pinMode(Trig, OUTPUT);
  	pinMode(Echo, INPUT);
	this->Trig = Trig;
	this->Echo = Echo;
	this->interval = interval;
	this->prev = millis();
	this->Speed = 0;
}
void BW_Auto::setNewSpeed(int speed)
{
	this->Speed = speed;
}
void BW_Auto::Update()
{
	
  for(int i = 0; i<=7; i++)
  {
     this->PinOuts[i] = this->Standart[i];
  }
	
}
void BW_Auto::Schritte(Stepper Schritte, int Pin1, int Pin2, int Pin3, int Pin4)
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
void BW_Auto::Forwards()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[0],this->PinOuts[1],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[4],this->PinOuts[5],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
}
void BW_Auto::Backwards()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[1],this->PinOuts[0],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[5],this->PinOuts[4],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
	
}
void BW_Auto::Left()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[0],this->PinOuts[1],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[5],this->PinOuts[4],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
}
void BW_Auto::Right()
{
	Update();
	
	for(int Schritt = Schritt_1; Schritt<=Schritt_4; Schritt++ )
	{
		Schritte(Schritt, this->PinOuts[1],this->PinOuts[0],this->PinOuts[2],this->PinOuts[3]);
		Schritte(Schritt, this->PinOuts[4],this->PinOuts[5],this->PinOuts[6],this->PinOuts[7]);
		delayMicroseconds(this->Speed);		
	}
}



unsigned long BW_Auto::distanz()
{
	if(millis() - prev > interval)
	{
		prev = millis();
		digitalWrite(Trig, LOW);
		delayMicroseconds(2);
		digitalWrite(Trig, HIGH);
		delayMicroseconds(10);
		digitalWrite(Trig, LOW);
		Messung = pulseIn(Echo, HIGH);
		Messung = (Messung/2)/29;
		return Messung;
	}
}
