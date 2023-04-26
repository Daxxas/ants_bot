#include "../Ant.h"
#include "../BT/BT_Sequence.h"

struct AIAnt
{
private:
  BT_Sequence root;

public:
  AIAnt();
  ~AIAnt();
  void run(Ant *ant, State *state);
};