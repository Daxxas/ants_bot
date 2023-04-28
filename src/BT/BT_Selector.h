#pragma once

#include "BT_CompositeNode.h"

class BT_Selector : public BT_CompositeNode
{
public:
    NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "Selector: " << this << std::endl;

        for (int i = 0; i < children.size(); ++i)
        {
            BT_Node *child = children[i];

            NodeStatus status = child->run(ant, state);
            //state->bug << "Sequence: " << child << " " << status << std::endl;

            // The generic BT_Selector implementation
            if (status == NodeStatus::SUCCESS)
            { // If one child succeeds, the entire operation run() succeeds.  Failure only results if all children fail.
                return NodeStatus::SUCCESS;
            }

            if (status == NodeStatus::RUNNING)
            { // If one child is running, the entire operation run() is running.
                return NodeStatus::RUNNING;
            }
        }

        return NodeStatus::FAILURE; // All children failed so the entire run() operation fails.
    }
};