#pragma once

#include "BT_CompositeNode.h"

class BT_Sequence : public BT_CompositeNode
{
public:
    NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "Sequence: " << this << std::endl;
        for (int i = 0; i < children.size(); ++i)
        {
            BT_Node *child = children[i];
            NodeStatus status = child->run(ant, state);
            state->bug << "Sequence: " << child << " " << status << std::endl;

            // The generic BT_Sequence implementation.
            if (status == NodeStatus::FAILURE) // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
                return NodeStatus::FAILURE;

            if (status == NodeStatus::RUNNING) // If one child is running, the entire operation run() is running.
                return NodeStatus::RUNNING;
        }
        return NodeStatus::SUCCESS; // All children suceeded, so the entire run() operation succeeds.
    }
};