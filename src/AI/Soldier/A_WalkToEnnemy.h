#include "../../bt/BT_Node.h"

class A_WalkToEnnemy : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::RUNNING;
  }
};