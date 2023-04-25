#include "../../BT/BT_Node.h"

#define MEETING_POINT_DISTANCE 3

class I_IsOnMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_IsOnMeetingPoint" << std::endl;

    if (ant->location.distance(ant->meetingPoint) <= MEETING_POINT_DISTANCE)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};