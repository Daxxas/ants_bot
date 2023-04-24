#pragma once

#include <list>
#include "BT_Node.h"

class BT_CompositeNode : public BT_Node
{ //  This type of BT_Node follows the Composit"e Pattern, containing a list of other Nodes.
private:
  std::list<BT_Node *> children;

public:
  const std::list<BT_Node *> &getChildren() const
  {
    return children;
  }

  void addChild(BT_Node *child)
  {
    children.emplace_back(child);
  }
};