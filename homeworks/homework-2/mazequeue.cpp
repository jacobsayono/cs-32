#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

class Coord
    {
        public:
        Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
        int r() const { return m_r; }
        int c() const { return m_c; }
        private:
        int m_r;
        int m_c;
    };


bool pathExists(char maze[][5], int sr, int sc, int er, int ec);

bool pathExists(char maze[][5], int sr, int sc, int er, int ec) {
    queue <Coord> coordinates;
    Coord a(sr, sc);

    //  Push the starting coordinate (sr,sc) onto the coordinate stack and
    //  update maze[sr][sc] to indicate that the algorithm has encountered
    //  it (i.e., set maze[sr][sc] to have a value other than '.').
    coordinates.push(a);
    maze[sr][sc] = 'O';

    // While the stack is not empty
    while (!coordinates.empty()) {

        // Pop the top coordinate off the stack. This gives you the current
        // (r,c) location that your algorithm is exploring.
        Coord current = coordinates.front();       
        coordinates.pop();                       
        
        int r = current.r();                
        int c = current.c();
        

        // If the current (r,c) coordinate is equal to the ending coordinate,
        // then we've solved the maze so return true!
        if (sr == er && sc == ec) {              
            return true;
        }
        
        if (r == er && c == ec) {              
            return true;
        }
        
        // Check South
        // If you can move SOUTH and haven't encountered that cell yet,
        // then push the coordinate (r+1,c) onto the stack and update
        // maze[r+1][c] to indicate the algorithm has encountered it.
        if (maze[r+1][c] == '.') {
            Coord s(r+1, c);
            coordinates.push(s);                   
            maze[r+1][c] = 'O';                
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }

        // Check East
        // If you can move EAST and haven't encountered that cell yet,
        // then push the coordinate (r,c+1) onto the stack and update
        // maze[r][c+1] to indicate the algorithm has encountered it.
        if (maze[r][c+1] == '.') {
            Coord e(r, c+1);
            coordinates.push(e);             
            maze[r][c+1] = 'O';     
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        
        // Check North
        // If you can move NORTH and haven't encountered that cell yet,
        // then push the coordinate (r-1,c) onto the stack and update
        // maze[r-1][c] to indicate the algorithm has encountered it.
        if (maze[r-1][c] == '.') {
            Coord n(r-1, c);
            coordinates.push(n);             
            maze[r-1][c] = 'O';             
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }

        // Check West
        // If you can move WEST and haven't encountered that cell yet,
        // then push the coordinate (r,c-1) onto the stack and update
        // maze[r][c-1] to indicate the algorithm has encountered it.
        if (maze[r][c-1] == '.') {
            Coord w(r, c-1);
            coordinates.push(w);                  
            maze[r][c-1] = 'O';               
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }

        cout << "next loop" << endl;

    }
    return false;
    
}

// int main()
//     {
//         queue<Coord> coordQueue;       // declare a queue of Coords

//         Coord a(5,6);
//         coordQueue.push(a);            // enqueue item at back of queue
//         coordQueue.push(Coord(3,4));   // enqueue item at back of queue
        
//         Coord b = coordQueue.front();  // look at front item
//         coordQueue.pop();              // remove the front item from queue
//         if (coordQueue.empty())        // Is the queue empty?
//             cout << "empty!" << endl;
//         cout << coordQueue.size() << endl;  // num of elements
//     }

// int main()
// {
//     char maze[10][10] = {
//         { 'X','X','X','X','X','X','X','X','X','X' },
//         { 'X','.','.','.','X','.','.','.','.','X' },
//         { 'X','.','.','X','X','.','X','X','.','X' },
//         { 'X','.','X','.','.','.','.','X','X','X' },
//         { 'X','X','X','X','.','X','X','X','.','X' },
//         { 'X','.','.','X','.','.','.','X','.','X' },
//         { 'X','.','.','X','.','X','.','.','.','X' },
//         { 'X','X','.','X','.','X','X','X','X','X' },
//         { 'X','.','.','.','.','.','.','.','.','X' },
//         { 'X','X','X','X','X','X','X','X','X','X' }
//     };

//     if (pathExists(maze, 3,4, 8,1))
//         cout << "Solvable!" << endl;
//     else
//         cout << "Out of luck!" << endl;
// }

int main()
{
    // char maze[10][10] = {
    //     { 'X','X','X','X','X','X','X','X','X','X' },
    //     { 'X','.','.','.','X','.','.','.','.','X' },
    //     { 'X','.','.','X','X','.','X','X','.','X' },
    //     { 'X','.','X','.','.','.','.','X','X','X' },
    //     { 'X','X','X','X','.','X','X','X','.','X' },
    //     { 'X','.','.','X','.','.','.','X','.','X' },
    //     { 'X','.','.','X','.','X','.','.','.','X' },
    //     { 'X','X','.','X','.','X','X','X','X','X' },
    //     { 'X','.','.','.','.','.','.','.','.','X' },
    //     { 'X','X','X','X','X','X','X','X','X','X' }
    // };

    // if (pathExists(maze, 3,4, 5,6))
    //     cout << "Solvable!" << endl;
    // else
    //     cout << "Out of luck!" << endl;

    // // Print the maze
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    char smallmaze[5][5] = {
        { 'X', 'X', 'X', 'X', 'X' },
        { 'X', '.', '.', '.', 'X' },
        { 'X', '.', 'X', '.', 'X' },
        { 'X', '.', '.', '.', 'X' },
        { 'X', 'X', 'X', 'X', 'X' }
    };

    if (pathExists(smallmaze, 1,1, 2,3)) {
        cout << "solvable" << endl;
    } else {
        cout << "not" << endl;
    }

    // Print the maze
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << smallmaze[i][j] << " ";
        }
        cout << endl;
    }

}