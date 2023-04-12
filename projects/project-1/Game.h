#ifndef GAME_H
#define GAME_H

#include "Arena.h"

#include <string>
using namespace std;

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};

#endif /* GAME_H */