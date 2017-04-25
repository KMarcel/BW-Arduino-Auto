#include <BW_Auto.h>
BW_Auto Auto(3, 2, 0, 1, 8, 9, 10, 11, 7, 6, 100);
unsigned long An = 0;

void setup() {
  Auto.setNewSpeed(2500);
}

void loop() {
    An = Auto.distanz(false);
    if(An >= 15)
    {
      Auto.Forwards();
    }else
    {
      Auto.Backwards(20);
      Auto.Left(50);
      delay(1000);
      An = Auto.distanz(true);
      if(An < 15)
      {
        Auto.Right(95);
        delay(1000);
        An = Auto.distanz(true);
        if(An < 15)
        {
          Auto.Right(50);
        }
      }
    }
    
}
