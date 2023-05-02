#include "../../BT/BT_Node.h"

// Return SUCCESS if the ant has a hill destination, FAILURE otherwise
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