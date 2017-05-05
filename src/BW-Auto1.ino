#include <BW_Auto.h>
BW_Auto Auto(3, 2, 0, 1, 8, 9, 10, 11, 7, 6, 100);
unsigned long An = 16;
int Links = 0;
void setup() {
  Auto.setNewSpeed(3000);
}

void loop() {
  An = Auto.distanz(false);
  if(An > 300)
  {
    Auto.setInterval(1000);
  }
  if(An > 200)
  {
    Auto.setInterval(400);
  }
  if(An > 100)
  {
    Auto.setInterval(100);
  }
  if(An < 15)
  {
    Auto.setInterval(50);
  }
  if(An >= 15)
  {
    Auto.setNewSpeed(3000);
    Auto.Forwards();
  }else{
    Links = 0;
    Auto.setNewSpeed(7000);
    while(An < 15 && Links < 10)
    {      
      Auto.Left(4);
      An = Auto.distanz(false);
      Links++;
    }
    An = Auto.distanz(true);
    while(An < 15)
    {      
      Auto.Right(5);
      An = Auto.distanz(false);
    }
  }
}
