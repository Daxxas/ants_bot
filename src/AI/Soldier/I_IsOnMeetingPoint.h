#include "../../bt/BT_Node.h"

class I_IsOnMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant, State &state) override
  {
    // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};