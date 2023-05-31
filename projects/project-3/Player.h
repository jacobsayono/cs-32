#include <iostream>

#ifndef Player_h
#define Player_h

#include "Board.h"
#include <stdio.h>

class Player {
    public:
        Player(std::string name);
            // Create a Player with the indicated name.
        std::string name() const;
            // Return the name of the player.
        virtual bool isInteractive() const;
            // Return false if the player is a computer player. Return true if the player is human. Most kinds of players will be computer players.
        virtual int chooseMove(const Board& b, Side s) const = 0;
            // Every concrete class derived from this class must implement this function so that if the player were to be playing side s and had to make a move given board b, the function returns the move the player would choose. If no move is possible, return −1.
        virtual ~Player();
            // Since this class is designed as a base class, it should have a virtual destructor.

    private:
        std::string _name;
        Side _side;
        Side getSide() const;
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(std::string name);
        bool isInteractive() const;
        int chooseMove(const Board& b, Side s) const;
};

class BadPlayer : public Player {
    public:
        BadPlayer(std::string name);
        bool isInteractive() const;
        int chooseMove(const Board& b, Side s) const;
};

class SmartPlayer : public Player {
    public:
        SmartPlayer(std::string name);
        bool isInteractive() const;
        int chooseMove(const Board& b, Side s) const;
    private:
        int evaluate(Board& b, Side s, int hole, int& depth, int& value, Side original) const;
        int chooseMoveHelper(const Board& b, Side s, int& bestHole, int& value) const;
        Side notSide(Side s) const;
};

#endif /* Player_h */