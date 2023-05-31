#include <iostream>

const int SIZE = 100;

class Stack {
    public:
        Stack();  // constructor
        
        void push (int val);  // add item to stack, takes int as a parameter
        int pop();  // remove item from stack, returns an int
        bool s_empty(void);  // check if stack s empty
        int peek_top();  // check the value of the top element
    
    private:
        int m_stack[SIZE];  // use an array to hold our stack items, holding a max of 100 items
        int m_top;  // keep track of where the next item should be added to the stack
};

Stack::Stack() {
    m_top = 0;  // initialize our stack, specifying first item should go in the 0th slot of the array 
}

void Stack::push(int val) {
    if (m_top >= SIZE) {
        exit(-1);  // stack overflow
    }

    m_stack[m_top] = val;  // place our new value in the next open slot of the array, m_top specifies where that s
    m_top += 1;  // update the location for where the next item should be placed in the array

    // post-increment: increment after storing the value
}

int Stack::pop() {
    if (m_top == 0) {
        exit(-1);  // we can't pop an item from our stack if it's empty. stack underflow
    }

    m_top -= 1;
    return m_stack[m_top];

    // pre-decrement: decrement before returning
}

int main() {
    Stack s;

    s.push(5);
    s.push(10);

    int a = s.pop();
    std::cout << a << std::endl;

    s.push(7);
}