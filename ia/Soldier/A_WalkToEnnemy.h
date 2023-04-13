#include "../../bt/Node.h"

class A_WalkToEnnemy : public Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::RUNNING;
  }
};