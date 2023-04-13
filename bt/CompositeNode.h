#include <list>
#include "Node.h"

class CompositeNode : public Node
{ //  This type of Node follows the Composit"e Pattern, containing a list of other Nodes.
private:
  std::list<Node *> children;

public:
  const std::list<Node *> &getChildren() const
  {
    return children;
  }

  void addChild(Node *child)
  {
    children.emplace_back(child);
  }
};