#pragma once

#include "CompositeNode.h"

class Sequence : public CompositeNode
{
public:
  virtual NodeStatus run(Ant &ant) override
  {
    for (Node *child : getChildren())
    {
      NodeStatus status = child->run(ant);
      // The generic Sequence implementation.
      if (status == NodeStatus::FAILURE) // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
        return NodeStatus::FAILURE;

      if (status == NodeStatus::RUNNING) // If one child is running, the entire operation run() is running.
        return NodeStatus::RUNNING;
    }
    return NodeStatus::SUCCESS; // All children suceeded, so the entire run() operation succeeds.
  }
};