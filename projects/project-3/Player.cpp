#include <string>
#include "Player.h"
using namespace std;

Player::Player(string name)
: _name(name) {}

string Player::name() const {
    return _name;
}

bool Player::isInteractive() const {
    return false;
}

int Player::chooseMove(const Board& b, Side s) const {
    return -1;
}

Player::~Player() {}







HumanPlayer::HumanPlayer(string name)
: Player(name) {}

bool HumanPlayer::isInteractive() const {
    return true;
}

int HumanPlayer::chooseMove(const Board& b, Side s) const {
    if (b.beansInPlay(NORTH) == 0 || b.beansInPlay(SOUTH) == 0) {
        return -1;
    }

    cout << this->name() << " hole selection: ";
    int move;
    cin >> move;

    if (move <= 0 || move > b.holes() || b.beans(s, move) == 0) {
        if (b.beans(s, move) == 0) {
            cout << "no beans in that hole" << endl;
        }
        else {
            if (b.holes() == 1) {
                cout << "hole number must be 1" << endl;
            }
            else {
                cout << "hole number must be between 1 to " << b.holes() << endl;
            }
        }
        return chooseMove(b, s);
    }
    else {
        return move;
    }
}







BadPlayer::BadPlayer(string name)
: Player(name) {}

int BadPlayer::chooseMove(const Board& b, Side s) const {
    if (s == NORTH) {
        int i = 1;
        while (i <= b.holes()) {
            if (b.beans(NORTH, i) != 0) {
                return i;
            }
            i++;
        }
    }
    if (s == SOUTH) {
        int i = 1;
        while (i <= b.holes()) {
            if (b.beans(SOUTH, i) != 0) {
                return i;
            }
            i++;
        }
    }

    return -1;
}

bool BadPlayer::isInteractive() const {
    return false;
}







SmartPlayer::SmartPlayer(string name)
: Player(name) {}

int SmartPlayer::chooseMove(const Board& b, Side s) const {
    int best_hole = 1;
    int value = 0;

    return chooseMoveHelper(b, s, best_hole, value);
}

bool SmartPlayer::isInteractive() const {
    return false;
}

int SmartPlayer::chooseMoveHelper(const Board& b, Side s, int& bestHole, int& value) const {
    Board board_copy = b;
    Board original = b;

    int depth = 5;
    if (board_copy.beansInPlay(s) == 0) {
        bestHole = -1;
        value = evaluate(board_copy, s, bestHole, depth, value, s);
        return bestHole;
    }

    int max = -1000;
    for (int i = 1; i <= board_copy.holes(); i++) {
        depth = 5;
        value = 0;
        board_copy = original;

        if (board_copy.beans(s, i) > 0) {
            int this_max = evaluate(board_copy, s, i , depth, value, s);
            if (max < this_max) {
                max = this_max;
                bestHole = i;
            }
        }

        if (max == 1000) {
            return bestHole;
        }

        board_copy = original;
        if (i + 1 > board_copy.holes() || board_copy.beans(s, i + 1) == 0) {
            continue;
        }
        depth = 5;
        value = 0;
        if (max <= evaluate(board_copy, s, i + 1, depth, value, s)) {
            bestHole = i + 1;
            max = evaluate(board_copy, s, i + 1, depth, value, s);
        }
    }

    depth = 5;
    evaluate(board_copy, s, bestHole, depth, value, s);
    return bestHole;
}

int SmartPlayer::evaluate(Board& b, Side s, int hole, int& depth, int& value, Side original) const {
    if (depth == 0) {
        return value;
    }

    int end = 0;
    Side x;
    if (!b.sow(s, hole, x, end)) {
        return value;
    }

    if (end == 0) {
        if (b.beansInPlay(NORTH) != 0 && b.beansInPlay(SOUTH) != 0) {
            int max = -1000;
            Board current = b;

            for (int i = 1; i <= b.holes(); i++) {
                b = current;
                value = 0;

                int check = evaluate(b, s, i, depth, value, original);
                if (max <= check) {
                    max = check;
                }
                return max;
            }
        }
        if (x == s && b.beans(s, end) == 1 && b.beans(notSide(s), end) > 0) {
            b.moveToPot(notSide(s), end, s);
            b.moveToPot(s, end, s);
        }
        if (original == NORTH) {
            if (b.beans(original, 0) > b.beans(SOUTH, 0)) {
                value = 1000;
            }
            else if (b.beans(original, 0) < b.beans(SOUTH, 0)) {
                value = -1000;
            }
            else {
                value = 0;
            }
        }
        else if (original == SOUTH) {
            if (b.beans(original, 0) > b.beans(SOUTH, 0)) {
                value = 1000;
            }
            else if (b.beans(original, 0) < b.beans(SOUTH, 0)) {
                value = -1000;
            }
            else {
                value = 0;
            }
        }
        return value;
    }

    value = b.beans(original, 0)- b.beans(notSide(original), 0);

    if (s == original) {
        depth--;
        int current_min = 1000;
        Board copy = b;

        for (int i = 1; i < b.holes(); i++) {
            b = copy;
            if (original == SOUTH) {
                if (b.beans(NORTH, i) == 0) {
                    continue;
                }
                int check = evaluate(b, NORTH, i, depth, value, original);
                if (current_min > check) {
                    current_min = check;
                }
            }
            else {
                if (b.beans(SOUTH, i) == 0) {
                    continue;
                }
                int check = evaluate(b, SOUTH, i, depth, value, original);
                if (current_min > check) {
                    current_min = check;
                }
            }
        }

        int check = 0;
        if (original == SOUTH) {
            check = evaluate(b, NORTH, b.holes(), depth, value, original);
        }
        else {
            check = evaluate(b, SOUTH, b.holes(), depth, value, original);
        }
        if (check < current_min) {
            current_min = check;
        }
        return current_min;
    }
    else {
        depth--;
        int current_max = -1000;
        Board copy = b;
        for (int i = 1; i < b.holes(); i++) {
            b = copy;
            if (original == SOUTH) {
                if (b.beans(SOUTH, i) == 0) {
                    continue;
                }
                int check = evaluate(b, SOUTH, i, depth, value, original);
                if (current_max < check) {
                    current_max = check;
                }
            }
            else {
                if (b.beans(NORTH, i) == 0) {
                    continue;
                }
                int check = evaluate(b, NORTH, i , depth, value, original);
                if (current_max < check) {
                    current_max = check;
                }
            }
        }
        int check = 0;
        if (original == SOUTH) {
            check = evaluate(b, SOUTH, b.holes(), depth, value, original);
        }
        else {
            check = evaluate(b, NORTH, b.holes(), depth, value, original);
        }
        if (check > current_max) {
            current_max = check;
        }
        return current_max;
    }
}

Side SmartPlayer::notSide(Side s) const {
    if (s == SOUTH) {
        return NORTH;
    }
    else {
        return SOUTH;
    }
}