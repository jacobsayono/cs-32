#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

// change ItemType to std::string

int main() {
    Sequence s;
    assert(s.empty());
    assert(s.find("laobing") == -1);
    assert(s.insert("laobing") == 0);
    assert(s.size() == 1  &&  s.find("laobing") == 0);

    Sequence s1;
    s1.insert(0, "alpha");
    s1.insert(1, "beta");
    s1.insert(2, "chocolate");
    s1.insert(3, "delta");
    s1.insert(4, "epsilon");
    s1.insert(5, "fire");
    s1.insert(6, "gamma");
    s1.dump();


    Sequence s2;
    s2.dump();
    s2.insert(0, "hello");
    s2.dump();
    s1.swap(s2);
    s1.dump();
    s2.dump();

    Sequence s3;
    s3.swap(s2);
    s2.dump();
    s3.dump();

    Sequence s;
    s.insert(0, "d");
    s.insert(1, "e");
    s.insert(2, "s");
    s.insert(3, "l");
    s.dump();
    Sequence ss;
    ss.insert(0, "w");
    ss.insert(1, "r");
    ss.insert(2, "g");
    ss.insert(3, "h");
    ss.insert(4, "s");
    ss.insert(5, "9");
    ss.insert(6, "u");
    ss.insert(7, "x");
    ss.dump();
    ss.swap(s);
    s.dump();
    ss.dump();

    Sequence ss1;
    ss1.insert(0, "google");
    Sequence ss2;
    ss2.insert(0, "alexa");
    ss2.insert(1, "siri");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.find("alexa") == 0  &&  ss1.find("siri") == 1  &&
            ss2.size() == 1  &&  ss2.find("google") == 0);
}