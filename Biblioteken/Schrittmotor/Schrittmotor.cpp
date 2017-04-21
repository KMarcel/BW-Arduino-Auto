/****************************************************************************
 Titel	:   Schrittmotoren Library für das Projekt Arduino Auto
 Autor:    Marcel Kühl <Marcel.Kuehl@web.de>  http://github.com/KMarcel
 Datei:	    Schrittmotor.cpp
 Software:  Arduino IDE
 Beschreibung
       In dieser Schrittmotor.cpp Datei sind alle wichtigen Funktionen
	   zum Ansteuern beider Schrittmotoren vorhanden
       
*****************************************************************************/
#include <Arduino.h>
#include <Schrittmotor.h>
Schrittmotor::Schrittmotor(int Pin1, int Pin2, int Pin3, int Pin4,
			   int Pin5, int Pin6, int Pin7, int Pin8)
{
	
/** Die Übertragen Pins werden nun in Globale Variablen gespeichert die man in anderen Funktionen verwenden kann **/
/** this-> stellt die Globale Variable dar **/
this->Pin1 = Pin1;
this->Pin2 = Pin2;
this->Pin3 = Pin3;
this->Pin4 = Pin4;
this->Pin5 = Pin5;
this->Pin6 = Pin6;
this->Pin7 = Pin7;
this->Pin8 = Pin8;
	
	pinMode(Pin1, OUTPUT);
	pinMode(Pin2, OUTPUT);
	pinMode(Pin3, OUTPUT);
	pinMode(Pin4, OUTPUT);
	pinMode(Pin5, OUTPUT);
	pinMode(Pin6, OUTPUT);
	pinMode(Pin7, OUTPUT);
	pinMode(Pin8, OUTPUT);
	
	this->Standart[0] = Pin1;
	this->Standart[1] = Pin2;
	this->Standart[2] = Pin3;
	this->Standart[3] = Pin4;
	this->Standart[4] = Pin5;
	this->Standart[5] = Pin6;
	this->Standart[6] = Pin7;
	this->Standart[7] = Pin8;
	
	this->Speed = 0;
}
void Schrittmotor::setNewSpeed(int speed)
{
	this->Speed = speed;
}
void Schrittmotor::Update()
{
	this->Pin1 = Standart[0];
	this->Pin2 = Standart[1];
	this->Pin3 = Standart[2];
	this->Pin4 = Standart[3];
	this->Pin5 = Standart[4];
	this->Pin6 = Standart[5];
	this->Pin7 = Standart[6];
	this->Pin8 = Standart[7];
}
void Schrittmotor::Schritte()
{
	digitalWrite(this->Pin1, HIGH);
	digitalWrite(this->Pin2, LOW);
	digitalWrite(this->Pin3, HIGH);
	digitalWrite(this->Pin4, LOW);

	digitalWrite(this->Pin5, HIGH);
	digitalWrite(this->Pin6, LOW);
	digitalWrite(this->Pin7, HIGH);
	digitalWrite(this->Pin8, LOW);

	delayMicroseconds(this->Speed);
	  
	digitalWrite(this->Pin1, LOW);
	digitalWrite(this->Pin2, HIGH);
	digitalWrite(this->Pin3, HIGH);
	digitalWrite(this->Pin4, LOW);

	digitalWrite(this->Pin5, LOW);
	digitalWrite(this->Pin6, HIGH);
	digitalWrite(this->Pin7, HIGH);
	digitalWrite(this->Pin8, LOW);

	delayMicroseconds(this->Speed);

	digitalWrite(this->Pin1, LOW);
	digitalWrite(this->Pin2, HIGH);
	digitalWrite(this->Pin3, LOW);
	digitalWrite(this->Pin4, HIGH);

	digitalWrite(this->Pin5, LOW);
	digitalWrite(this->Pin6, HIGH);
	digitalWrite(this->Pin7, LOW);
	digitalWrite(this->Pin8, HIGH);

	delayMicroseconds(this->Speed);

	digitalWrite(this->Pin1, HIGH);
	digitalWrite(this->Pin2, LOW);
	digitalWrite(this->Pin3, LOW);
	digitalWrite(this->Pin4, HIGH);

	digitalWrite(this->Pin5, HIGH);
	digitalWrite(this->Pin6, LOW);
	digitalWrite(this->Pin7, LOW);
	digitalWrite(this->Pin8, HIGH);

	delayMicroseconds(this->Speed);
}
void Schrittmotor::Forwards()
{
	Update();
	Schritte();
}
void Schrittmotor::Backwards()
{
	Update();
	int Zwischenspeicher1 = this->Pin5;
	this->Pin5 = this->Pin6;
	this->Pin6 = Zwischenspeicher1;
	Zwischenspeicher1 = this->Pin1;
	this->Pin1 = this->Pin2;
	this->Pin2 = Zwischenspeicher1;
	Schritte();
}
void Schrittmotor::Left()
{
	Update();
	int Zwischenspeicher1 = this->Pin5;
	this->Pin5 = this->Pin6;
	this->Pin6 = Zwischenspeicher1;
	Schritte();
}
void Schrittmotor::Right()
{
	Update();
	int Zwischenspeicher1 = this->Pin1;
	this->Pin1 = this->Pin2;
	this->Pin2 = Zwischenspeicher1;
	Schritte();
}
