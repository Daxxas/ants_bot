#include "../Ant.h"
#include "../bt/BT_Selector.h"

struct AIAnt
{
private:
  Ant &ant;
  BT_Selector root;

public:
  AIAnt(Ant &ant);
  void run();
};