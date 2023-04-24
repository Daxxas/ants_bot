#include "../../bt/BT_Node.h"

class I_HasMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant, State &state) override
  {
    if (ant.hasMeetingPoint)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};