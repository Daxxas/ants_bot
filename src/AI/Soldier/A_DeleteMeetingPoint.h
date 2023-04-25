#include "../../BT/BT_Node.h"

class A_DeleteMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_DeleteMeetingPoint" << std::endl;

    // TODO: Implement this method.
    return NodeStatus::RUNNING;
  }
};