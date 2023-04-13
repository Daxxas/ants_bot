#include "../Ant.h"

class Node
{ // This class represents each node in the behaviour tree.
public:
	virtual bool run(Ant &ant) = 0;
};