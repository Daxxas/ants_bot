#include "../Ant.h"
#include "../bt/BT_Selector.h"

struct AIAnt
{
private:
  Ant &ant;
  State &state;
  BT_Selector root;

public:
  AIAnt(Ant &ant, State &state);
  void run();
};