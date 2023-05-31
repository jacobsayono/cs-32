#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(const Board& b, Player* south, Player* north)
: _board(b), _south_player(south), _north_player(north), _whose_turn(_south_player), _over(false) {}

void Game::display() const {
    if (_board.holes() <= 3) {
        cout << "    ";
    }
    else {
        cout << "        ";
    }
    cout << _north_player->name() << endl;
    cout << "    ";
    
    int countSpaces = 1;
    for (int i = 1; i <= _board.holes(); i++) {
        cout << beans(NORTH, i) << "   ";
        countSpaces += 3;
    }
    cout << endl;
    
    cout << " " << beans(NORTH, 0);
    int i = 0;
    while (i < countSpaces) {
        cout << " ";
        i++;
    }
    cout << beans(SOUTH, 0) << endl;
    cout << "    ";
    for (int i = 1; i <= _board.holes(); i++) {
        cout << beans(SOUTH, i) << "    ";
    }
    cout << endl;
    
    if (_board.holes() <= 3) {
        cout << "    ";
    }
    else {
        cout << "        ";
    }
    cout << _south_player->name() << endl;
    
}

void Game::status(bool& over, bool& hasWinner, Side& winner) const {
    if (_board.beansInPlay(NORTH) > 0 && _board.beansInPlay(SOUTH) > 0) {
        over = false;
        return;
    }
    else {
        over = true;
        if (beans(NORTH, 0) > beans(SOUTH, 0)) {
            hasWinner = true;
            winner = NORTH;
        }
        else if (beans(SOUTH, 0) > beans(NORTH, 0)) {
            hasWinner = true;
            winner = SOUTH;
        }
        else
            hasWinner = false;
    }
    
}

bool Game::move(Side s) {
    display();
    status(_over, _has_winner, _winner);

    if (_over) {
        // Do any necessary sweeping
        if (_board.beansInPlay(NORTH) == 0 && _board.beansInPlay(SOUTH) != 0) {
            for (int i = 1; i <= _board.holes(); i++)
                _board.moveToPot(SOUTH, i, SOUTH);
            cout << "sweeping the remaining beans into " << _south_player->name() << "'s pot" << endl;
        }
        else if (_board.beansInPlay(NORTH) != 0 && _board.beansInPlay(SOUTH) == 0) {
            for (int i = 1; i <= _board.holes(); i++)
                _board.moveToPot(NORTH, i, NORTH);
            cout << "sweeping the remaining beans into " << _north_player->name() << "'s pot" << endl;
        }

        // Update status and display
        status(_over, _has_winner, _winner);
        display();
        return false;
    }

    int hole = _whose_turn->chooseMove(_board, s);
    int end = 0;
    Side moveSide;

    if (!_whose_turn->isInteractive())
        cout << _whose_turn->name() << " chooses hole " << hole << endl;

    bool completedMove = _board.sow(s, hole, moveSide, end);

    if (completedMove) {
        status(_over, _has_winner, _winner);

        if (_over)
            return move(s); // If the move ended the game, recursively call move() to handle sweeping and additional turns

        if (end == 0) {
            display();
            cout << _whose_turn->name() << " gets another turn" << endl;
            return move(s); // If the player gets another turn, recursively call move() to handle the next move
        }
        else if (moveSide == s && beans(moveSide, end) == 1 && beans(notSide(_whose_turn), end) > 0) {
            _board.moveToPot(notSide(_whose_turn), end, moveSide);
            _board.moveToPot(moveSide, end, moveSide);
        }
    }

    _whose_turn = (_whose_turn == _south_player) ? _north_player : _south_player; // Switch to the other player's turn
    return true;
}

void Game::play() {
    _play(false, 0);
}

int Game::beans(Side s, int hole) const {
    return _board.beans(s, hole);
}

Side Game::turnSide(Player* turn) {
    if (_whose_turn == _south_player)
        return SOUTH;
    else
        return NORTH;
}

Side Game::notSide(Player* turn) {
    if (_whose_turn == _south_player)
        return NORTH;
    else
        return SOUTH;
}

Player* Game::playerSide(Side s) {
    if (s == SOUTH)
        return _south_player;
    else
        return _north_player;
}

void Game::_play(bool s, int k) {
    if (!_north_player->isInteractive() && !_south_player->isInteractive()) {
        if (move(turnSide(_whose_turn))) {
            if (s)
            {
                cout << "hit ENTER";
                if (k == 1)
                {
                    string enter;
                    getline(cin, enter);
                }
                cin.ignore(10000, '\n');
                cout << endl;
            }
            _play(!s, k+1);
        }
        else {
            if (_has_winner == false)
                cout << "time game" << endl;
            else
                cout << "winner is " << playerSide(_winner)->name() << endl;
        }
    }
    else {
        if (move(turnSide(_whose_turn)))
            _play(!s, k+1);
        else {
            if (_has_winner == false)
                cout << "time game" << endl;
            else
                cout << "winner is " << playerSide(_winner)->name() << endl;
        }
    }
    
    return;
}