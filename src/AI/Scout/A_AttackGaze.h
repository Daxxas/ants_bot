#include "../../BT/BT_Node.h"

class A_AttackGaze : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "Attack hill" << std::endl;

      return NodeStatus::FAILURE;
  }
};