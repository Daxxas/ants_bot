#include <iostream>

// Parameters for the AI
#define SQUARE_TO_CHECK 7       // Square to check for ennemy (must be odd)
#define ANT_TO_HILL_DISTANCE 10 // Min distance to and hill to send the ant into it

#include "AIAnt.h"
#include "../BT/BT_Selector.h"
#include "../BT/BT_Sequence.h"

// Include all leef
#include "./Soldier/I_HasHillDestination.h"
#include "./Soldier/I_NoEnnemyNearby.h"
#include "./Soldier/I_NoHillsNearby.h"
#include "./Soldier/A_AttackEnnemy.h"
#include "./Soldier/A_AttackHill.h"
#include "./Soldier/A_WalkToHillDestination.h"

#include "./Scout/A_MoveToBestDirection.h"

AIAnt::AIAnt()
{
    // Initiate the Behaviour Tree

    // Soldier
    BT_Selector *p_soldier = new BT_Selector();
    root.addChild(p_soldier);

    // Soldier/Hill Destination
    BT_Sequence *p_hillDestination = new BT_Sequence();
    p_soldier->addChild(p_hillDestination);

    I_HasHillDestination *p_hasHillDestination = new I_HasHillDestination();
    p_hillDestination->addChild(p_hasHillDestination);

    A_WalkToHillDestination *p_walkToHillDestination = new A_WalkToHillDestination();
    p_hillDestination->addChild(p_walkToHillDestination);

    // Soldier/Gaze
    BT_Sequence *p_gaze = new BT_Sequence();
    p_soldier->addChild(p_gaze);

    I_NoHillsNearby *p_noHillsNearby = new I_NoHillsNearby();
    p_gaze->addChild(p_noHillsNearby);

    A_AttackHill *p_attackHill = new A_AttackHill();
    p_gaze->addChild(p_attackHill);

    // Soldier/Ennemy
    BT_Sequence *p_ennemy = new BT_Sequence();
    p_soldier->addChild(p_ennemy);

    I_NoEnnemyNearby *p_noEnnemyNearby = new I_NoEnnemyNearby();
    p_ennemy->addChild(p_noEnnemyNearby);

    A_AttackEnnemy *p_attackEnnemy = new A_AttackEnnemy();
    p_ennemy->addChild(p_attackEnnemy);

    // Scout
    BT_Selector *p_scout = new BT_Selector();
    root.addChild(p_scout);

    // Scout
    A_MoveToBestDirection *p_moveToBestDirection = new A_MoveToBestDirection();
    p_scout->addChild(p_moveToBestDirection);
}

AIAnt::~AIAnt()
{
    for (int i = 0; i < root.children.size(); i++)
    {
        delete root.children[i];
    }
}

void AIAnt::run(Ant *ant, State *state)
{
    state->bug << "Run AI ant " << ant << std::endl;

    root.run(ant, state);
}