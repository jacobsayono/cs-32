#include "newSequence.h"
#include <iostream>

Sequence::Sequence() {
    length = 0;
    max_length = DEFAULT_MAX_ITEMS;
    array = new ItemType[max_length];
}

Sequence::Sequence(int maxSize) {
    if (maxSize < 0)
        exit(1);
    
    length = 0;
    max_length = maxSize;
    array = new ItemType[max_length];
}

Sequence::~Sequence() {
    delete [] array;
}

Sequence::Sequence(const Sequence& seq) {
    length = seq.length;
    max_length = seq.max_length;
    array = new ItemType[max_length];
    for (int i = 0; i < length; i++)
        array[i] = seq.array[i];
}

Sequence &Sequence::operator=(const Sequence& seq) {
    if (&seq == this)
        return *this;
    
    delete [] array;
    length = seq.length;
    max_length = seq.max_length;
    array = new ItemType[max_length];
    for (int i = 0; i < length; i++)
        array[i] = seq.array[i];
    return *this;
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

void Sequence::swap(Sequence& other) {
    int temp_length = size();
    length = other.size();
    other.length = temp_length;
    
    int temp_max_length = max_length;
    max_length = other.max_length;
    other.max_length = temp_max_length;
    
    ItemType* tempSequence = array;
    array = other.array;
    other.array = tempSequence;
}