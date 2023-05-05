#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;  // std::stack<type> variableName

    s.push(10);  // add item to top
    s.push(20);

    std::cout << s.top();  // get top value
    s.pop();  // kill top value
    // STL pop() command simply throws away the top item from the stack... but it doesn't return it

    if (s.empty() == false) {
        std::cout << s.size();
    }

    /*
    
    so here we have:
    top()
    push()
    pop()
    size()

    */
}