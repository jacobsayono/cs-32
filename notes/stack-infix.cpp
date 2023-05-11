#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Returns the precedence of the operator
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

// Converts an infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char token = infix[i];

        if (token == ' ') {
            continue;
        }
        else if (isdigit(token) || isalpha(token)) {
            postfix += token;
            postfix += " ";
        }
        else if (token == '(') {
            opStack.push(token);
        }
        else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }

            if (!opStack.empty()) {
                opStack.pop();
            }
        }
        else { // token is an operator
            while (!opStack.empty() && precedence(token) <= precedence(opStack.top())) {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }

            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a + b * c - d / e";
    string postfix = infixToPostfix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    string infixNUM = "3 + 6 * 7 * 8 - 3";
    string postfixNUM = infixToPostfix(infixNUM);

    cout << "Infix: " << infixNUM << endl;
    cout << "Postfix: " << postfixNUM << endl;

    string infixNUMparenthesis = "(3 + 5) * (4 + 3 / 2) - 5";
    string postfixNUMparenthesis = infixToPostfix(infixNUMparenthesis);

    cout << "Infix: " << infixNUMparenthesis << endl;
    cout << "Postfix: " << postfixNUMparenthesis << endl;

    return 0;
}
