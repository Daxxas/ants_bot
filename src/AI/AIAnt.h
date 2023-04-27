#include "../Ant.h"
#include "../BT/BT_Selector.h"

struct AIAnt
{
private:
  BT_Selector root;

public:
  AIAnt();
  ~AIAnt();
  void run(Ant *ant, State *state);
};