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
    if (m_grid[r][c] == '.') {
        m_grid[r][c] = 'A';
    } else if (m_grid[r][c] == 'Z') {
        m_grid[r][c] = 'Z';
    } else {
        m_grid[r][c]++;
    }
    return true;
}

void History::display() const {
    clearScreen();

    for (int r = 1; r <= m_rows; r++) {
        for (int c = 1; c <= m_cols; c++) {
            char character = m_grid[r][c] + 'A' - 1;
            
            if (m_grid[r][c] == 0) {
                cout << ".";
                continue;
            }
            else if (m_grid[r][c] >= 26) {
                cout << "Z";
                continue;
            }
            else {
                cout << character; 
            }
        }
        
        cout << endl;
    }

    cout << endl;
}