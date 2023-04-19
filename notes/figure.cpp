#include <iostream>
#include <cstdlib>  // for exit()
#include <cmath>  // for atan()
using namespace std;

// interface (what) vs. implementation (how)
// 1. COMPILATION: translating code into machine language
// 2. LINKING: resolve any requests the machine language (some code for that function)



/* FUNCTION DECLARATION */

class Circle {
    public:
        Circle(double x, double y, double r);  // constructor
        bool scale(double factor);
        void draw() const;  // function will not change the object
        double radius() const;  // the object you call this on will not be modified by this function
    private:
            // Class invariant (thinking about constraints):
            // r_ > 0 (radius mmust be positive)
        double x_;
        double y_;
        double r_;
};

double area(const Circle& x);  // our circle object will remain unchanged when using this non-member function

class StickFigure {
    public:
        StickFigure(double body_length, double head_diameter, string name, double head_x, double head_y);
    private:
        // the order in which the data members is constructed (in step 2) is determined by the order of declared private members in the class
        string name_;
        Circle head_;  // x_, y_, r_
        double body_length_;
};

/* FUNCTION IMPLEMENTATION */

Circle::Circle(double x, double y, double r)
: x_(x), y_(y), r_(r) {  // good way to initialize constructors
    if (r <= 0) {
        cout << "cannot create a circle with radius " << r << endl;
        exit(1);  // exit the program  
    }
    // x_ = x;
    // y_ = y;
    // r_ = r;
}

bool Circle::scale(double factor) {
    if (factor <= 0) {
        return false;
    }
    r_ *= factor;
    return true;
}

void Circle::draw() const {
    // ... draw a circle centered at (x_, y_) with radius r_ ...
}

double area(const Circle& x) {
    const double PI = 4 * atan(1.0);  // use a standard library to define value of PI
    return PI * x.radius() * x.radius();
}

double Circle::radius() const {
    return r_;
}

StickFigure::StickFigure(double body_length, double head_diameter, string name, double head_x, double head_y) 
: name_(name), head_(head_x, head_y, head_diameter/2), body_length_(body_length) {  // member initialization list, same order as declared members (so no warnings and efficient)
    if (body_length <= 0 || head_diameter <= 0) {
        // ... error ...
    }

    // name_ = name;
    // head_ = Circle(head_x, head_y, head_diameter/2);
    // body_length_ = body_length;

    /*
    compiler goes through 3 steps for construction:
    1) inheritance
    2) construct the data members, consulting the member initialization list
        if a data member is not listed in the member initialization list:
            if it's of a built-in type (like double), it's left uninitialized
            if it's of a class type, that class' default constructor is called
    3) execute the body code of the constructor inside {}
    */
}


/* MAIN DRIVER CODE */

int main() {
    Circle c(8, -3, 3.7);
    c.scale(2);  // member function
    c.draw();
    cout << area(c);  // not a member function that relate to the object
    double z;
    cin >> z;
    if (!c.scale(z)) {  // if the return is false, we know there's an error
        // ... error ...
    }
    
    return 0;
}



/*

circle.h
========

#include <string>

class Circle {
    public:
        Circle(double x, double y, double r);
        void blah(std::string s);
        ...
    private:
        ...
};

double area(const Circle& x);



circle.cpp
==========

#include "circle.h"
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;  // ok to use namspace in .cpp file bc this file won't "include" to other files

Circle::Circle(...)
: ... {
    ...
}

void Circle::blah(string s) {
    ...
}

double area(const Circle& x) {
    ...
}



main.cpp
========

#include "circle.h"
#include <iostream>
using namespace std;

int main() {
    Circle c(-8, 3, 3.7);
    cout << area(c);

    return 0;
}

*/