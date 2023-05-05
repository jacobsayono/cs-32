/*

used for:
1) storing undo items for your word processor
    the last item you typed is the first to be undone!
2) evaluating mathematical expressions
    5 + 6 * 3 -> 23
3) converting from infix expressions to postfix expressions
    A + B -> A B +
4) solving mazes

every CPU has a built-in stack used to hold local variables and function parameters

*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    string input;
    getline(cin, input);

    int num = 0;  // temp variable to accumulate all digits before a ';' separation char

    // store string input into int stack
    for (int i = 0; i < input.size(); i++) {

        if (isdigit(input.at(i))) {  // if token is a number
            num = num * 10 + (input.at(i) - '0');  // convert char to int, accumulate digit value
        }

        if (input.at(i) == ' ' && input.at(i - 1) != '+') {
            s.push(num);  // push number onto stack
            num = 0;  // reset accumulated number
        }

        if (input.at(i) == '+') {
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            s.pop();
            int result = v1 + v2;
            s.push(result);
        }
    }

    cout << s.top() << endl;
}