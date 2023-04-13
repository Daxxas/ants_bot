#include "CompositeNode.h"

class Sequence : public CompositeNode
{
public:
  virtual bool run(Ant &ant) override
  {
    for (Node *child : getChildren())
    {                       // The generic Sequence implementation.
      if (!child->run(ant)) // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
        return false;
    }
    return true; // All children suceeded, so the entire run() operation succeeds.
  }
};