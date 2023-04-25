#pragma once

#include "BT_Node.h"

class BT_CompositeNode : public BT_Node
{ //  This type of BT_Node follows the Composit"e Pattern, containing a list of other Nodes.
private:
public:
  ~BT_CompositeNode()
  {
    for (auto child : children)
    {
      delete child;
    }
  }

  std::vector<BT_Node *> children;

  //  const std::list<BT_Node *> getChildren() const
  //  {
  //    return children;
  //  }

  void addChild(BT_Node *child)
  {
    children.emplace_back(child);
  }
};