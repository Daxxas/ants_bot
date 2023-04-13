#include "CompositeNode.h"

class Selector : public CompositeNode
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    for (Node &child : getChildren())
    {
      NodeStatus status = child.run(ant);
      // The generic Selector implementation
      if (status == NodeStatus::SUCCESS) // If one child succeeds, the entire operation run() succeeds.  Failure only results if all children fail.
        return NodeStatus::SUCCESS;

      if (status == NodeStatus::RUNNING) // If one child is running, the entire operation run() is running.
        return NodeStatus::RUNNING;
    }
    return NodeStatus::FAILURE; // All children failed so the entire run() operation fails.
  }
};