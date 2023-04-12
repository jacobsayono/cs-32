#include "History.h"

#include <iostream>
using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
}

bool History::record(int r, int c) {
    if (r <= 0  ||  c <= 0  ||  r > m_rows  ||  c > m_cols) {
        return false;
    }

    history_grid[r][c] = history_grid[r][c] + 1;

    return true;
}

void History::display() const {
    clearScreen();

    for (int r = 1; r <= m_rows; r++) {
        for (int c = 1; c <= m_cols; c++) {
            /*
            This command shows you for each grid point,
            how many times a rabbit had started its turn poisoned but alive at that grid point
            (i.e., the rabbit had previously eaten one poisoned carrot
            but had not previously eaten a second one):
            
            dot means 0,
            a letter character A through Y means 1 through 25 (A means 1, B means 2, etc.),
            and Z means 26 or more.
            */
            char printchar = history_grid[r][c] + 64;
            if (history_grid[r][c] >= 26) {
                 cout << "Z";
                continue;
            }
            if (history_grid[r][c] == 0) {
                cout << ".";
                continue;
            }
            cout << printchar; 
        }
        cout << endl;
    }
    cout << endl;
}