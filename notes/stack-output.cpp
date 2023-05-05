#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    s.push(6);
    for (int i = 0; i < 2; i++) {
        int n = s.top();
        s.pop();
        s.push(i);
        s.push(n*2);
    }

    for (int i = 0; i < 3; i++) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    // if exit bounds of array, will compile but runtime error: segmentation fault
}

/*
initial stack:
6

after loop 0:
12
0

after loop 1:
24
1
0
*/