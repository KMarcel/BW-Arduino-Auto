#ifndef SCHRITTMOTOR_H
#define SCHRITTMOTOR_H

#include <Arduino.h>

class Schrittmotor
{
	public:
		Schrittmotor(int Pin1, int Pin2, int Pin3, int Pin4,
			     int Pin5, int Pin6, int Pin7, int Pin8);
		void Left();
		void Right();
		void Forwards();
		void Backwards();
		void setNewSpeed(int speed);
	private:
		void Schritte();
		void Update();
		int Real[8];
		long Speed;
		int Pin1 = 0;
		int Pin2 = 0;
		int Pin3 = 0;
		int Pin4 = 0;
		int Pin5 = 0;
		int Pin6 = 0;
		int Pin7 = 0;
		int Pin8 = 0;
	
	
};
#endif
