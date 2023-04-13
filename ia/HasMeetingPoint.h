#include "../bt/Node.h"

class HasMeetingPoint : public Node
{ //  This type of Node follows the Composit"e Pattern, containing a list of other Nodes.
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