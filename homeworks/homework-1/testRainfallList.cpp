#include "RainfallList.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    RainfallList rfl;
    assert(rfl.size() == 0);
    assert(rfl.add(20) && rfl.add(33) && rfl.add(1) && rfl.add(17) && !rfl.add(12));
    assert(rfl.size() == 4);
}