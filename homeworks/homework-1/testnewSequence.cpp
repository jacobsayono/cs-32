#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
	Sequence s;
	assert(s.empty());
	assert(s.find(22) == -1);
	assert(s.insert(22) == 0);
	assert(s.size() == 1 && s.find(22) == 0);
	assert(s.insert(44) == 0);
	assert(s.insert(22) == 2);
	assert(s.insert(22) == 2);
	assert(s.erase(0));
	assert(s.size() == 3);
	assert(s.remove(52));
	assert(s.size() == 1);

	Sequence b(3);
	assert(b.empty());
	assert(b.find(22) == -1);
	assert(b.insert(22) == 0);
	assert(b.size() == 1 && b.find(22) == 0);
	assert(b.insert(44) == 0);
	assert(b.insert(22) == 2);
	assert(b.insert(22) == -1);
	assert(b.erase(0));
	assert(b.size() == 2);
	assert(b.remove(22));
	assert(b.size() == 1);

    Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
    ItemType v = 3;

    // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++)
        assert(b.insert(v) != -1);

    // Failure if we try to insert a sixth item into b
    assert(b.insert(v) == -1);

    // When two Sequences' contents are swapped, their capacities are
    // swapped as well:
    a.swap(b);
    assert(a.insert(v) == -1  &&  b.insert(v) != -1);
	
	return 0;
}