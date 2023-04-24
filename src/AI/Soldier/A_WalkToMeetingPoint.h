#include "../../BT/BT_Node.h"

class A_WalkToMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant, State &state) override
  {
    // TODO: Implement this method.
    return NodeStatus::RUNNING;
  }
};