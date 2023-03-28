#include <iostream>
#include <string>
#include "swap.h"

int main() {
    HoldOneValue<int> v1;
    v1.setVal(10);
    v1.printThreeTimes();

    std::cout << std::endl;

    HoldOneValue<char> v2;
    v2.setVal('o');
    v2.printThreeTimes();

    std::cout << std::endl;

    HoldOneValue<int> vv;
    vv.setVal(12);

    swap(v1, vv);
    v1.printThreeTimes();
    vv.printThreeTimes();

    HoldOneValue<char> vvv;
    vvv.setVal('n');

    swap(v2, vvv);
    v2.printThreeTimes();
    vvv.printThreeTimes();

    Dog<int> a(13), b(31);

    std::string x("a"), y("b");
    swap(a, b);
    swap(x, y);

    Dog<int> dog1(10), dog2(5);
    if (dog1 > dog2) {
        std::cout << "fat" << std::endl;
    }
    else {
        std::cout << "another fatty" << std::endl;
    }

    std::cout << ((dog2 > dog1) ? "fat" : "another fatty") << std::endl;

    foo(5, "barf");


    Cat fido(10);
    LinkedList<Dog<int>> doglist;
    doglist.ins(a);

    LinkedList<Cat> catlist;
    catlist.ins(fido);

    LinkedList<std::string> names;
    names.ins("vika");
    names.ins("jacob");

}