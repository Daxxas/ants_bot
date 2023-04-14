#include "../../bt/Node.h"

#define MEETING_POINT_DISTANCE 3

class I_IsOnMeetingPoint : public Node
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    if (ant.location.distance(ant.meetingPoint) <= MEETING_POINT_DISTANCE)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};