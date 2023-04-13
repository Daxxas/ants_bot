#include "../bt/Node.h"

class IsOnMeetingPoint : public Node
{ //  This type of Node follows the Composit"e Pattern, containing a list of other Nodes.
public:
  virtual NodeStatus run(Ant &ant) override
  {
    // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};