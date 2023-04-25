#include "../../BT/BT_Node.h"

class I_HasMeetingPoint : public BT_Node
{
public:
  NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_HasMeetingPoint" << std::endl;

    if (ant->hasMeetingPoint)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};