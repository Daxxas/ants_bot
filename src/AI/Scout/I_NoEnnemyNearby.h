#include "../../bt/BT_Node.h"

class I_NoEnnemyNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::SUCCESS;
  }
};