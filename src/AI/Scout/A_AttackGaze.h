#include "../../BT/BT_Node.h"

class A_AttackGaze : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "A_AttackGaze" << std::endl;

      return NodeStatus::SUCCESS;
  }
};