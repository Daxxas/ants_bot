#include "../../BT/BT_Node.h"

class I_HasHillDestination : public BT_Node
{
public:
  NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_HasHillDestination" << std::endl;

    if (ant->hasHillDestination)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};