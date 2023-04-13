#include "../bt/Node.h"

class HasMeetingPoint : public Node
{ //  This type of Node follows the Composit"e Pattern, containing a list of other Nodes.
public:
  virtual bool run(Ant &ant) override
  {
    return ant.hasMeetingPoint;
  }
};