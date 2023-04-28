#include "Bot.h"
#include "../AI/AIAnt.h"
// #include "BFS.h"

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
        state.updateFoodDestination();
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
    AIAnt aiAnt;
    state.bug << "Ants number: " << (int)state.myAnts.size() << endl;

    // picks out moves for each ant
    for (int ant = 0; ant < (int)state.myAnts.size(); ant++)
    {
        state.bug << "Ant n°" << ant << " " << state.myAnts[ant].location << " at turn " << state.turn << " ===============================" << endl;
        // state.myAnts[ant].bfsMap = BFS::GenerateBFS(&state, &state.myAnts[ant].location);

        aiAnt.run(&state.myAnts[ant], &state);

        //        for (int d = 0; d < TDIRECTIONS; d++)
        //        {
        //
        //          // Faut mettre le code la dedans
        //            Location loc = state.getLocation(state.myAnts[ant].location, d);
        //
        //            if (!state.grid[loc.row][loc.col].isWater)
        //            {
        //                state.makeMove(state.myAnts[ant].location, d);
        //                break;
        //            }
        //        }
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
