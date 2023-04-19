#include "Sequence.h"
#include <iostream>

Sequence::Sequence() {
    length = 0;
}

bool Sequence::empty() const {
    if (length == 0) {
        return true;
    }
    else {
        return false;
    }
} 

int Sequence::size() const {
    return length;
}
    
bool Sequence::get(int i, ItemType& value) const {
    if (0 <= i && i < size()) {
        value = array[i];
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

    
void Sequence::dump() const {
    for (int i = 0; i < size(); i++) {
        std::cerr << array[i] << " ";
    }
    std::cerr << "size(): " << size() << std::endl;
}

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0 || pos > length) {
        return -1;
    }

    if (length == DEFAULT_MAX_ITEMS) {
        return -1;
    }

    for (int i = length; i > pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos] = value;
    length++;

    return pos;
}


int Sequence::insert(const ItemType& value)
{
    int pos;
    for (pos = 0; pos < length; pos++) {
        if (value <= array[pos]) {
            break;
        }
    }

    if (pos < DEFAULT_MAX_ITEMS && length < DEFAULT_MAX_ITEMS) {
        for (int i = length; i > pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos] = value;
        length++;
        return pos;
    }
    else {
        return -1;
    }
}


bool Sequence::erase(int pos) {
    if (0 <= pos && pos < size())
    {
        for (int i = pos; i < size()-1; i++)
            array[i] = array[i+1];
        length -= 1;
        return true;
    }
    else
        return false;
}

int Sequence::remove(const ItemType& value) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            for (int j = i; j < length - 1; j++) {
                array[j] = array[j + 1];
            }
            count++;
            length--;
            i--;  // need to check the current index again
        }
    }
    return count;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < 0 || pos >= length) {
        return false;
    }
    array[pos] = value;
    return true;
}

void Sequence::swap(Sequence& other)
{
    int tempSize = size();
    length = other.size();
    other.length = tempSize;

    int largerSize = size();
    if (size() < other.size())
        largerSize = other.size();

    for (int i = 0; i < largerSize; i++)
    {
        ItemType tempItem = array[i];
        array[i] = other.array[i];
        other.array[i] = tempItem;
    }
}