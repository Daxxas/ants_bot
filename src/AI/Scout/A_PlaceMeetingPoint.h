#include "../../bt/BT_Node.h"

class A_PlaceMeetingPoint : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "A_PlaceMeetingPoint" << std::endl;


      // TODO: Implement this method.
    return NodeStatus::FAILURE;
  }
};