#include <iostream>

class Quadratic {
    public:
        Quadratic(int a, int b, int c);
        ~Quadratic();
        int evaluate(int x);

    private:
        int m_a;
        int m_b;
        int m_c;
};

Quadratic::Quadratic(int a, int b, int c)
: m_a(a), m_b(b), m_c(c) {}  // initialization list for primitive data types not required

Quadratic::~Quadratic() {
    std::cout << "goodbye" << std::endl;
}

int Quadratic::evaluate(int x) {
    return (m_a * x * x) + (m_b * x) + (m_c);
}



class MathNerd {
    public:
        MathNerd(int a, int b);
        ~MathNerd();
        int getMyValue(int x);

    private:
        Quadratic equation;
};

MathNerd::MathNerd(int a, int b)
: equation(a, b, 0) {}  // initialization list for non-primitive data types

MathNerd::~MathNerd() {
    std::cout << "done" << std::endl;
}

int MathNerd::getMyValue(int x) {
    return equation.evaluate(x);
}



int main() {
    MathNerd nerdy(1, 2);  // a = 1, b = 2, c = 0
    std::cout << nerdy.getMyValue(3) << std::endl;  // x = 3
}