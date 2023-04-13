#include "../Ant.h"

struct AIAnt
{
private:
  Ant &ant;

public:
  AIAnt(Ant &ant);
  void run();
};