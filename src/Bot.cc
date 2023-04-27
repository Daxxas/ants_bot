#include "Bot.h"
#include "../AI/AIAnt.h"

using namespace std;

// constructor
Bot::Bot(){

};

// plays a single game of Ants.
void Bot::playGame()
{
    // reads the game parameters and sets up
    cin >> state;
    state.setup();
    endTurn();

    // continues making moves while the game is not over
    while (cin >> state)
    {
        state.updateVisionInformation();
        state.applyHillsDestination();
        state.updateExploreGrid();
        makeMoves();
        state.saveHillsDestination();
        endTurn();
    }
};

// makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    state.bug << state << endl;
    state.displayExploreGrid();
    AIAnt aiAnt;
    state.bug << "Ants number: " << (int)state.myAnts.size() << endl;

    // picks out moves for each ant
    for (int ant = 0; ant < (int)state.myAnts.size(); ant++)
    {
        state.bug << "Ant n°" << ant << " " << state.myAnts[ant].location << " at turn " << state.turn << " ===============================" << endl;

        aiAnt.run(&state.myAnts[ant], &state);
    }

    state.bug << "time taken: " << state.timer.getTime() << "ms" << endl
              << endl;
};

// finishes the turn
void Bot::endTurn()
{
    if (state.turn > 0)
        state.reset();
    state.turn++;

    cout << "go" << endl;
};
