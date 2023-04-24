#include "../../BT/BT_Node.h"

class I_IsOnMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant, State &state) override
  {
    if (ant.location == ant.meetingPoint)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};