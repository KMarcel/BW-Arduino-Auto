#ifndef BW_Auto_H
#define BW_Auto_H

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
/*************************************************************************
 Title	:   Arduino Library für zwei BW_Autoen des Arduino Auto weitere Informationen zum Projekt auf https://github.com/KMarcel/Arduino-Auto
 Author:    Marrcel Kühl <Marcel.Kuehl@web.de>  https://github.com/KMarcel
 File:	    BW_Auto.h und BW_Auto.cpp
 Software:  Arduino IDE
 Hardware:  Arduino Serie 
***************************************************************************/
/*@{*/
class BW_Auto
{
// Private Variablen und Funktionen die nur in der Klasse verwendet werden können
private:

/** interval für die Messung **/
unsigned int interval = 0;

/** Letzte Zeitmessung millis  **/
long prev = 0;


/** Trigger pin für die Komunikation zwischen Mikrocontroller und Sensor **/
int Trig = 0;


/** Echo pin für die Komunikation zwischen Mikrocontroller und Sensor **/
int Echo = 0;




/** in diesem Int Array werden die Standart Pins hinterlegt **/
int Standart[8];

/** Hier wird die Geschwindigkeit der Halbschritte in Mikrosekunden angegeben sie sollte nicht unter 1500 fallen **/
unsigned int Speed;

/** Pins 1 bis 8 **/

		int Pin1 = 0;
		int Pin2 = 0;
		int Pin3 = 0;
		int Pin4 = 0;
		int Pin5 = 0;
		int Pin6 = 0;
		int Pin7 = 0;
		int Pin8 = 0;

/** Stepper als eigene Variablen **/
enum Stepper {Schritt_1, Schritt_2, Schritt_3, Schritt_4};

/**
 @brief    Erstellt eine Schrittkette zur verfügung diese Schrittkette ist in 4 Halbschritten unterteilt
 @param    void                                        
 @return   none
*/
void Schritte();


/**
 @brief    Diese Update funktion soll die Standart konfiguration wieder herstellen, die durch die verwendung der anderen Funktionen ensteht.
 @param    void                                        
 @return   none
*/
void Update(void);	
// Öffentliche Funktionen die man außerhaben mit einem Objekt aufrufen kann
public:
/**
 @brief    Konfiguriert die Pins für die BW_Autoen und ist wichtig für die erstellung von einem Objekt
 @param    void                                        
 @return   none
*/
BW_Auto(int Pin1, int Pin2, int Pin3, int Pin4, int Pin5, int Pin6, int Pin7, int Pin8,int Trig, int Echo, unsigned int interval);
				 
/**
 @brief    Motor 1 läuft Vorwärts Motor 2 läuft Rückwärts
 @param    void                                        
 @return   none
*/
void Left(void);
void Left(int Anzahl);


/**
 @brief    Motor 1 läuft Rückwärts Motor 2 läuft Vorwärts
 @param    void                                        
 @return   none
*/
void Right(void);
void Right(int Anzahl);

/**
 @brief    Motor 1 läuft Vorwärts Motor 2 läuft Vorwärts
 @param    void                                        
 @return   none
*/
void Forwards(void);
void Forwards(int Anzahl);

/**
 @brief    Motor 1 läuft Rückwärts Motor 2 läuft Rückwärts
 @param    void                                        
 @return   none
*/
void Backwards(void);
void Backwards(int Anzahl);
/**
 @brief    Hier kann man eine Neue Geschwindigkeit für die einzelenen Halbschritte festlegen.
 @param    void                                        
 @return   none
*/
void setNewSpeed(int speed);
void setInterval(unsigned int Interval);
/**
 @brief    Konfiguriert die Pins für die BW_Autoen und ist wichtig für die erstellung von einem Objekt
 @param    void                                        
 @return   none
*/
unsigned long distanz(bool M);

};
#endif
