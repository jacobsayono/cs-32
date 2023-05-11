#include <iostream>
#include <stack>

using namespace std;

const int ROW = 10;
const int COL = 10;

int maze[ROW][COL] = {  // Example maze (0 for path, 1 for wall)
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,1,1,1,1,0},
    {0,0,0,1,0,0,0,1,0,0},
    {0,1,0,0,0,1,0,0,1,0},
    {0,1,1,1,1,0,0,1,1,0},
    {0,1,0,0,1,0,1,0,1,0},
    {0,1,1,0,1,0,1,0,1,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0}
};

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= ROW || y >= COL) {
        return false;
    }
    if (maze[x][y] == 1) {
        return false;
    }
    return true;
}

bool solveMaze(int sx, int sy, int ex, int ey) {
    stack<Point> stk;
    stk.push(Point(sx, sy));
    maze[sx][sy] = 2;  // Mark starting point as discovered

    while (!stk.empty()) {
        Point cur = stk.top();
        stk.pop();

        if (cur.x == ex && cur.y == ey) {  // We've reached the endpoint
            return true;
        }

        // Check all valid directions
        if (isValid(cur.x - 1, cur.y)) {  // West
            maze[cur.x - 1][cur.y] = 2;  // Mark as discovered
            stk.push(Point(cur.x - 1, cur.y));
        }
        if (isValid(cur.x + 1, cur.y)) {  // East
            maze[cur.x + 1][cur.y] = 2;
            stk.push(Point(cur.x + 1, cur.y));
        }
        if (isValid(cur.x, cur.y - 1)) {  // North
            maze[cur.x][cur.y - 1] = 2;
            stk.push(Point(cur.x, cur.y - 1));
        }
        if (isValid(cur.x, cur.y + 1)) {  // South
            maze[cur.x][cur.y + 1] = 2;
            stk.push(Point(cur.x, cur.y + 1));
        }
    }

    return false;  // Maze is unsolvable
}

int main() {
    int sx = 1, sy = 1;  // Starting point
    int ex = 8, ey = 8;  // Ending point

    if (solveMaze(sx, sy, ex, ey)) {
        cout << "Maze is solvable!\n";
    } else {
    cout << "Maze is unsolvable.\n";
    }
}
