#include "../../BT/BT_Node.h"

class A_DeleteMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_DeleteMeetingPoint" << std::endl;

    ant->hasMeetingPoint = false;

    return NodeStatus::SUCCESS;
  }
};