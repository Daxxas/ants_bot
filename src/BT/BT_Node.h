#pragma once

#include <string>
#include "../Ant.h"
#include "../State.h"

enum NodeStatus : short
{
	FAILURE,
	SUCCESS,
	RUNNING
};

class BT_Node
{ // This class represents each node in the behaviour tree.
public:
	virtual NodeStatus run(Ant *ant, State *state) = 0;
};