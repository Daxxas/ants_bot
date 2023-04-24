#include "../../bt/BT_Node.h"

class I_NoGazeNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
      state->bug << "I_NoGazeNearby" << std::endl;


      // TODO: Implement this method.
    return NodeStatus::SUCCESS;
  }
};