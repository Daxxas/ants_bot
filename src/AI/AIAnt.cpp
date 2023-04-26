#include <iostream>

#define SQUARE_TO_CHECK 7 // Square to check (must be odd)
#define SEND_X_ANT 3
#define ANT_TO_HILL_DISTANCE 10

#include "AIAnt.h"
#include "../BT/BT_Selector.h"
#include "../BT/BT_Sequence.h"

// Include all leef
#include "./Soldier/I_NoEnnemyNearby.h"
#include "./Soldier/I_NoHillsNearby.h"
#include "./Soldier/A_AttackEnnemy.h"
#include "./Soldier/A_AttackHill.h"

#include "./Scout/A_MoveToBestDirection.h"

AIAnt::AIAnt()
{
    // Soldier
    BT_Sequence *soldier = new BT_Sequence();
    root.addChild(soldier);

    // Soldier/Gaze
    BT_Selector *gaze = new BT_Selector();
    soldier->addChild(gaze);

    I_NoHillsNearby *noHillsNearby = new I_NoHillsNearby();
    gaze->addChild(noHillsNearby);

    A_AttackHill *attackHill = new A_AttackHill();
    gaze->addChild(attackHill);

    // Soldier/Ennemy
    BT_Selector *ennemy = new BT_Selector();
    soldier->addChild(ennemy);

    I_NoEnnemyNearby *noEnnemyNearby = new I_NoEnnemyNearby();
    ennemy->addChild(noEnnemyNearby);

    A_AttackEnnemy *attackEnnemy = new A_AttackEnnemy();
    ennemy->addChild(attackEnnemy);

    // Scout
    BT_Sequence *scout = new BT_Sequence();
    root.addChild(scout);

    // Scout
    A_MoveToBestDirection *moveToBestDirection = new A_MoveToBestDirection();
    scout->addChild(moveToBestDirection);
}

AIAnt::~AIAnt()
{
    // TODO : Faire le delete
    // delete pointeur;
}

void AIAnt::run(Ant *ant, State *state)
{
    state->bug << "Run AI ant " << ant << std::endl;

    root.run(ant, state);
}