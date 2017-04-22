#include <BW_Auto.h>
int Abstand = 0;
int Pins[8] = {3, 4, 5, 6, 8, 9, 10, 11};
BW_Auto Auto(Pins, 1, 2, 2000);

void setup() {
  Auto.setNewSpeed(2000);
}

void loop() {
  Abstand = Auto.distanz();
  if(Abstand > 30)
  {
    Auto.Forwards();
  }
  if(Abstand < 30)
  {
    Auto.Backwards(20);
    Auto.Left(90);
    Abstand = Auto.distanz();
    if(Abstand < 50)
    {
      Auto.Right(180); 
      Abstand = Auto.distanz();
      if(Abstand < 50)
      {
        Auto.Right(90);
      }
    }     
  }
}
