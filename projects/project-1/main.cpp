// Project 1 big bag o' test cases

// If you uncomment the #define line immediately below this comment and
// replace the integer with an integer in the range 1 to 20, when you build
// the program, the compiler will select the code below corresponding to
// that integer.  (For any other integer, it will use the original code that
// plays the game.)  Here is the line to uncomment:

#define TESTNUM 0

// fix TESTNUM 15, 16, 17, 18, 19, 20

// (If you know how to specify a value for TESTNUM at the time you invoke the
// compiler, using either a project setting in Visual C++ or Xcode or by
// defining the value on the command line, you could leave the #define line
// above commented out and instead set TESTNUM that other way.)

#ifndef TESTNUM  // In case you haven't already defined the name TESTNUM
#define TESTNUM 0
#endif

#if TESTNUM == 0

#include "Game.h"

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 5, 2);
    // Game g(10, 12, 40);
    Game g(3, 5, 2);

      // Play the game
    g.play();
}

#elif TESTNUM == 1

#include "Rabbit.h"
int main() {}

#elif TESTNUM == 2

#include "Player.h"
int main() {}

#elif TESTNUM == 3

#include "Arena.h"
int main() {}

#elif TESTNUM == 4

#include "Game.h"
int main() {}

#elif TESTNUM == 5

#include "globals.h"
int main() {}

#elif TESTNUM == 6

#include "Game.h"
#include "Game.h"
#include "Arena.h"
#include "Arena.h"
#include "History.h"
#include "History.h"
#include "Player.h"
#include "Player.h"
#include "Rabbit.h"
#include "Rabbit.h"
#include "globals.h"
#include "globals.h"
int main() {}

#elif TESTNUM == 7

#include "History.h"
int main()
{
    History h(2, 2);
    h.record(1, 1);
    h.display();
}

#elif TESTNUM == 8

#include "Rabbit.h"
int main()
{
    Rabbit r(nullptr, 1, 1);
}

#elif TESTNUM == 9

#include "Player.h"
int main()
{
    Player p(nullptr, 1, 1);
}

#elif TESTNUM == 10

#include "Arena.h"
int main()
{
    Arena a(10, 18);
    a.addPlayer(2, 2);
}

#elif TESTNUM == 11

#include "globals.h"
#include "Player.h"
#include "Arena.h"
int main()
{
    Arena a(10, 20);
    Player p(&a, 2, 3);
}

#elif TESTNUM == 12

#include "Arena.h"
#include "Player.h"
int main()
{
    Arena a(10, 20);
    Player p(&a, 2, 3);
}

#elif TESTNUM == 13

#include "Player.h"
#include "Arena.h"
int main()
{
    Arena a(10, 20);
    Player p(&a, 2, 3);
}

#elif TESTNUM == 14

#include "History.h"
#include "Arena.h"
#include <iostream>
using namespace std;

int main()
{
    Arena a(1, 3);
    a.history().record(1, 2);
    Arena a2(1, 2);
    a2.history().record(1, 1);
    a.history().display();
    cout << "===" << endl;
}

 /************
This must produce exactly three lines of output:
.A.

===
 ************/

#elif TESTNUM == 15

#include "Arena.h"
#include "History.h"
#include "globals.h"
// #include "Player.h"
#include <iostream>
using namespace std;

int main()
{
    Arena a(1, 4);
    a.addPlayer(1, 4);
    a.addRabbit(1, 1);
    // a.player()->dropPoisonedCarrot();
    // a.player()->move(EAST);
    // a.player()->move(EAST);
    a.setCellStatus(1, 2, HAS_POISON);
    while (a.getCellStatus(1, 2) == HAS_POISON)
        a.moveRabbits();
    a.moveRabbits();
    a.history().display();
    cout << "====" << endl;
}
 /************
This must produce exactly three lines of output:
.A..

====
 ************/

#elif TESTNUM == 16  // This test must NOT compile

#include "Rabbit.h"
#include "Arena.h"
int main()
{
    Arena a(10, 20);
    Player p(&a, 2, 3);
    Rabbit r(&a, 1, 1);
}

#elif TESTNUM == 17  // This test must NOT compile

#include "Player.h"
#include "Arena.h"
int main()
{
    Arena a(10, 20);
    Player p(&a, 2, 3);
    Rabbit r(&a, 1, 1);
}

#elif TESTNUM == 18  // This test must NOT compile

#include "globals.h"
#include "Rabbit.h"
#include "Player.h"
int main()
{
    Arena a(10, 10);
}

#elif TESTNUM == 19  // This test must NOT compile

#include "Game.h"
int main()
{
    Arena a(10, 10);
}

#elif TESTNUM == 20  // This test must NOT compile

#include "History.h"
int main()
{
    History h;
}

#else  // use original main.cpp

#include "Game.h"

int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 5, 2);
    Game g(10, 12, 40);

      // Play the game
    g.play();
}

#endif