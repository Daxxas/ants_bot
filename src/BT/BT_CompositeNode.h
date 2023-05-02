#pragma once

#include "BT_Node.h"

class BT_CompositeNode : public BT_Node
{ //  Composite node that contain a list of children nodes
private:
public:
  std::vector<BT_Node *> children;

  void addChild(BT_Node *child)
  {
    children.emplace_back(child);
  }
};