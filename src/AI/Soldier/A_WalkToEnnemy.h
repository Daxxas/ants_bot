#include "../../bt/BT_Node.h"

class A_WalkToEnnemy : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "A_WalkToEnnemy" << std::endl;


      // TODO: Implement this method.
    return NodeStatus::RUNNING;
  }
};