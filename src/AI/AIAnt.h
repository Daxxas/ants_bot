#include "../Ant.h"
#include "../bt/BT_Selector.h"

struct AIAnt
{
private:
  BT_Selector root;

public:
  AIAnt();
  ~AIAnt();
  void run(Ant* ant, State* state);
};