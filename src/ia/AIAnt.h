#include "../Ant.h"
#include "../bt/Selector.h"

struct AIAnt
{
private:
  Ant &ant;
  Selector root;

public:
  AIAnt(Ant &ant);
  void run();
};