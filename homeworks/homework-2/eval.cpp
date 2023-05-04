// eval.cpp Apurva Shah 705595011

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int evaluate(string infix, string &postfix, bool &result);
string removeSpaces(string input);
bool isValid(string input);
int getPresedence(char opp);
string prefixToPost(string infix);
bool charToBool(char value);
char boolToChar(bool value);
bool evaluatePostFix(string postfix);

bool charToBool(char value) {
    if (value == 'T') {
        return true;
    }
    else {
        return false;
    }
}

char boolToChar(bool value) {
    if (value == true) {
        return 'T';
    }
    else {
        return 'F';
    }
}

string removeSpaces(string input) {
    string temp = "";
    for (int i = 0; i < input.size(); i++)
        if (input[i] != ' ')
            temp += input[i];
    return temp;
}

int getPresedence(char opp) {
    switch (opp) {
    case '!':
        return 4;
    case '&':
        return 3;
    case '^':
        return 2;
    case '(':
        return 1;
    default:
        return -1;
    }
}

bool isValid(string input) {
    string infix;
    infix = removeSpaces(input);

    if (infix.size() == 0) {
        cerr << "Invalid because size 0" << endl;
        return false;
    }

    int paren_counter = 0;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(' || infix[i] == ')')
            paren_counter++;
    }
    if (paren_counter % 2 != 0) {
        cerr << "Invalid because mod failed" << endl;
        return false;
    }

    stack<char> paren_stack;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(')
            paren_stack.push(infix[i]);
        else {
            if (infix[i] == ')' && paren_stack.empty() == true) {
                cerr << "Invalid closing before opening" << endl;
                return false;
            }
            if (paren_stack.empty() != true) {
                char top_stack = paren_stack.top();
                if (infix[i] == ')' && top_stack == '(' && paren_stack.empty() != true)
         {
                    paren_stack.pop();
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }

    if (paren_stack.empty() == false) {
        cerr << "Invalid because something didn't pop" << endl;
        return false;
    }

    stack<int> paren_index;

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            paren_index.push(i);
            cerr << "Pushed: " << i << endl;
        }
        else {
            if (infix[i] == ')') {
                if (paren_index.top() + 1 < i)
         {
                    paren_index.pop();
                    continue;
                }
                else
         {
                    cerr << "Invalid because of something is in the parenthesis" << endl;
                    return false;
                }
            }
        }
    }

    for (int i = 0; i < infix.size(); i++) {
        char temp_val = infix[i];
        cerr << "index: " << i << ", value: " << infix[i] << ", next value: " << infix[i + 1] << endl;

        switch (temp_val) {
        case 'T':
            if (infix[i + 1] != ')' && infix[i + 1] != '^' && infix[i + 1] != '&' && i != infix.size() - 1) {
                cerr << "Failed at the T operand" << endl;
                return false;
            }
            break;
        case 'F':
            if (infix[i + 1] != ')' && infix[i + 1] != '^' && infix[i + 1] != '&' && i != infix.size() - 1) {
                cerr << "Failed at the F operand" << endl;
                return false;
            }
            break;
        case '&':
            if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i + 1] != '!') {
                cerr << "Failed at the & operator" << endl;
                return false;
            }
            if (infix[i - 1] != 'T' && infix[i - 1] != 'F' && infix[i - 1] != ')') {
                cerr << "Failed at the & operator" << endl;
                return false;
            }
            break;
        case '!':
            if (i == infix.size() - 1)
                return false;
            break;
        case '^':
            if (infix[i + 1] != 'T' && infix[i + 1] != 'F' && infix[i + 1] != '(' && infix[i + 1] != '!') {
                cerr << "Failed at the | operator" << endl;
                return false;
            }
            if (infix[i - 1] != 'T' && infix[i - 1] != 'F' && infix[i - 1] != ')') {
                cerr << "Failed at the | operator" << endl;
                return false;
            }
            break;
        case '(':
            break;
        case ')':
            break;
        default:
            return false;
        }
    }

    return true;

}

string prefixToPost(string infix) {
    string postfix = "";
    stack<char> opstack;

    for (int i = 0; i < infix.size(); i++) {
        char ch = infix[i];
        switch (ch) {
        case 'T':
            postfix += infix[i];
            break;
        case 'F':
            postfix += infix[i];
            break;
        case '(':
            opstack.push(ch);
            break;
        case ')':
            while (opstack.empty() != true && opstack.top() != '(') {
                postfix += opstack.top();
                opstack.pop();
            }
            if (!opstack.empty()) {
                opstack.pop();
            }
            break;
        case '&':
            while (opstack.empty() != true && opstack.top() != '(' && getPresedence(infix[i]) <= getPresedence(opstack.top())) {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        case '^':
            while (opstack.empty() != true && opstack.top() != '(' && getPresedence(infix[i]) <= getPresedence(opstack.top())) {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
        case '!':
            opstack.push(infix[i]);
            break;
        }
    }
    while (!opstack.empty()) {
        postfix += opstack.top();
        opstack.pop();
    }
    return postfix;
}

bool evaluatePostFix(string postfix) {
    stack<char> opstack;
    bool optop1;
    bool optop2;
    for (int i = 0; i < postfix.size(); i++) {

        char ch = postfix[i];
        if (ch == 'T' || ch == 'F') {
            opstack.push(ch);
            continue;
        }

        else if (ch == '!') {
            if (!opstack.empty()) {
                optop1 = charToBool(opstack.top());
                opstack.pop();
                opstack.push(boolToChar(!optop1));
                continue;
            }
        }
        else {
            if (ch == '&' && opstack.size() >= 2) {
                optop1 = charToBool(opstack.top());
                opstack.pop();
                optop2 = charToBool(opstack.top());
                opstack.pop();
                opstack.push(boolToChar(optop2 & optop1));
                continue;
            }
            if (ch == '^' && opstack.size() >= 2) {
                optop1 = charToBool(opstack.top());
                cerr << "optop1 is: " << optop1 << endl;
                opstack.pop();
                optop2 = charToBool(opstack.top());
                cerr << "optop2 is: " << optop2 << endl;
                opstack.pop();
                opstack.push(boolToChar(optop2 | optop1));
                continue;
            }
            continue;
        }
    }
    if (opstack.size() == 1)
        return charToBool(opstack.top());
    else {
        cerr << "VERY WRONG" << endl;
        return false;
    }
}

int evaluate(string infix, string &postfix, bool &result) {
    if (isValid(infix) == false) {
        cerr << "It is not valid" << endl;
        return 1;
    }
    else {
        postfix = prefixToPost(infix);
        result = evaluatePostFix(postfix);
        return 0;
    }
}

int main() {
    string pf;
    bool answer;
    assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
                            &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    cout << "Passed all tests" << endl;
}