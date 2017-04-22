#include <BW_Auto.h>
int Ergebnis = 0;
int Pins[8] = {0, 1, 2, 3, 8, 9, 10, 11};
BW_Auto Auto(Pins, 7, 6, 100);

void setup() {
  Auto.setNewSpeed(2000);
}

void loop() {
  Ergebnis = Auto.distanz();
  if(Ergebnis > 30)
  {
    Motoren.Forwards();
  }
  if(Ergebnis < 30)
  {
    Motoren.Left();
  }
}
