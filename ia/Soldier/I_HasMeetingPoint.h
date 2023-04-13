#include "../bt/Node.h"

class I_HasMeetingPoint : public Node
{
public:
  virtual NodeStatus run(Ant &ant) override
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