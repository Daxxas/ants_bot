#include "../../bt/Node.h"

class I_HasEnnemyNearby : public Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};