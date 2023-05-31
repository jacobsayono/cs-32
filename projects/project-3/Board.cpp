#include <iostream>
#include "Side.h"
#include "Board.h"

using namespace std;

Board::Board(int nHoles, int nInitialBeansPerHole) {
    // check initial conditions
    if (nInitialBeansPerHole < 0) {
        nInitialBeansPerHole = 0;
    }
    if (nHoles < 0) {
        nHoles = 1;
    }

    // initialize holes and sections of the board
    _total_holes = nHoles*2;
    _side_holes = nHoles;

    _south_pot = 0;
    _north_pot = 0;

    _north = new int[nHoles];
    _south = new int[nHoles];

    for (int i = 0; i < nHoles; i++) {
        _north[i] = nInitialBeansPerHole;
        _south[i] = nInitialBeansPerHole;
    }

    _total_beans = nInitialBeansPerHole * _total_holes;
}

int Board::holes() const {
    return _side_holes;
}

int Board::beans(Side s, int hole) const {
    if (s == NORTH) {
        if (hole == 0) {
            return _north_pot;
        }
        else if (hole <= holes()) {
            return _north[hole - 1];
        }
    }

    if (s == NORTH) {
        if (hole == 0) {
            return _south_pot;
        }
        else if (hole <= holes()) {
            return _south[hole - 1];
        }
    }

    return -1;
}

int Board::beansInPlay(Side s) const {
    if (s == NORTH) {
        int north_total = 0;
        for (int i = 0; i < holes(); i++) {
            north_total += _north[i];
        }
        return north_total;
    }

    if (s == SOUTH) {
        int south_total = 0;
        for (int j = 0; j < holes(); j++) {
            south_total += _south[j];
        }
        return south_total;
    }

    return 0;
}

int Board::totalBeans() const {
    return _total_beans;
}

bool Board::sow(Side s, int hole, Side& endSide, int& endHole) {
    if (hole > holes() || hole < 0) {
        return false;  // invalid hole
    }
    if (hole == 0) {
        return false;  // hole is pot
    }

    if (s == NORTH) {
        if (_north[hole - 1] == 0) {
            return false;  // hole is empty
        }

        int sow_beans = _north[hole - 1];
        _north[hole - 1] = 0;
        Side current_side = NORTH;
        int current_hole = hole - 1;

        while (sow_beans != 0) {
            if (current_side == NORTH && current_hole == 0) {
                _north_pot++;
                sow_beans--;
                current_side = SOUTH;
                current_hole = 1;
            }
            else if (current_side == NORTH) {
                _north[current_hole - 1]++;
                current_hole--;
                sow_beans--;
            }
            else if (current_side == SOUTH && current_hole > holes()) {
                current_side = NORTH;
                current_hole = holes();
            }
            else if (current_side == SOUTH) {
                _south[current_hole - 1]++;
                current_hole++;
                sow_beans--;
            }
        }

        endSide = current_side;

        if (endSide == SOUTH && current_hole == 1) {
            endSide = NORTH;
            endHole = 0;
        }
        else if (endSide == SOUTH) {
            endHole = current_hole - 1;
        }
        else if (endSide == NORTH) {
            endHole = current_hole + 1;
        }
    }

    if (s == SOUTH) {
        if (_south[hole - 1] == 0) {
            return false;  // hole is empty
        }

        int sow_beans = _south[hole - 1];
        _south[hole - 1] = 0;
        Side current_side = SOUTH;
        int current_hole = hole + 1;

        while (sow_beans != 0) {
            if (current_side == SOUTH && current_hole > holes()) {
                _south_pot++;
                sow_beans--;
                current_side = NORTH;
                current_hole = holes();
            }
            else if (current_side == SOUTH) {
                _south[current_hole - 1]++;
                current_hole++;
                sow_beans--;
            }
            else if (current_side == NORTH && current_hole == 0) {
                current_side = SOUTH;
                current_hole = 1;
            }
            else if (current_side == NORTH) {
                _north[current_hole - 1]++;
                current_hole--;
                sow_beans--;
            }
        }

        endSide = current_side;

        if (endSide == NORTH && current_hole == holes()) {
            endSide = SOUTH;
            endHole = 0;
        }
        else if (endSide == SOUTH) {
            endHole = current_hole - 1;
        }
        else if (endSide == NORTH) {
            endHole = current_hole + 1;
        }
    }

    return true;
}

bool Board::moveToPot(Side s, int hole, Side potOwner) {
    if (hole == 0) {
        return false;
    }
    if (hole > holes() || hole < 0) {
        return false;
    }

    if (s == NORTH) {
        int beans = _north[hole - 1];
        _north[hole - 1] = 0;
        
        if (potOwner == NORTH) {
            _north_pot += beans;
        }
        else if (potOwner == SOUTH) {
            _south_pot += beans;
        }
    }
    if (s == SOUTH) {
        int beans = _south[hole - 1];
        _south[hole - 1] = 0;
        
        if (potOwner == NORTH) {
            _north_pot += beans;
        }
        else if (potOwner == SOUTH) {
            _south_pot += beans;
        }
    }

    return true;
}

bool Board::setBeans(Side s, int hole, int beans) {
    if (beans < 0) {
        return false;
    }
    if (hole < 0 || hole > holes()) {
        return false;
    }

    if (s == NORTH) {
        if (hole == 0) {
            if (this->beans(NORTH, 0) < beans) {
                _north_pot = beans;
                _total_beans += beans;
            }
            else if (this->beans(NORTH, 0) == beans) {
                return true;
            }
            else {
                _total_beans -= _north_pot - beans;
                _north_pot = beans;
            }
        }
        else {
            if (this->beans(NORTH, hole) < beans) {
                _north[hole - 1] = beans;
                _total_beans += beans;
            }
            else if (this->beans(NORTH, hole) == beans) {
                return true;
            }
            else {
                _total_beans -= _north[hole - 1] - beans;
                _north[hole - 1] = beans;
            }
        }
    }

    if (s == SOUTH) {
        if (hole == 0) {
            if (this->beans(SOUTH, 0) < beans) {
                _south_pot = beans;
                _total_beans += beans;
            }
            else if (this->beans(SOUTH, 0) == beans) {
                return true;
            }
            else {
                _total_beans -= _south_pot - beans;
                _south_pot = beans;
            }
        }
        else {
            if (this->beans(SOUTH, hole) < beans) {
                _south[hole - 1] = beans;
                _total_beans += beans;
            }
            else if (this->beans(SOUTH, hole) == beans) {
                return true;
            }
            else {
                _total_beans -= _south[hole - 1] - beans;
                _south[hole - 1] = beans;
            }
        }
    }

    return true;
}

Board::~Board() {
    delete [] _north;
    delete [] _south;
}

Board::Board(const Board& other)
: _total_holes(other._total_holes), _side_holes(other._side_holes), _total_beans(other._total_beans), _north_pot(other._north_pot), _south_pot(other._south_pot) {
    _north = new int[_side_holes];
    _south = new int[_side_holes];

    for (int i = 0; i < holes(); i++) {
        _north[i] = other._north[i];
        _south[i] = other._south[i];
    }
}

Board& Board::operator=(const Board& rhs) {
    if (this != &rhs) {
        delete [] _north;
        delete [] _south;

        _total_holes = rhs._total_holes;
        _side_holes = rhs._side_holes;
        _total_beans = rhs._total_beans;
        _north_pot = rhs._north_pot;
        _south_pot = rhs._south_pot;

        _north = new int[_side_holes];
        _south = new int[_side_holes];

        for (int i = 0; i < holes(); i++) {
            _north[i] = rhs._north[i];
            _south[i] = rhs._south[i];
        }
    }

    return *this;
}