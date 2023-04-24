#include "../../bt/BT_Node.h"

class I_IsMoreThanEnnemy : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "I_IsMoreThanEnnemy" << std::endl;

    // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};