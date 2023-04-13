#include "../bt/Node.h"

class I_IsMoreThanEnnemy : public Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};