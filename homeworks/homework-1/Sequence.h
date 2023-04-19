#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
using ItemType = unsigned long;

const int DEFAULT_MAX_ITEMS = 160;

class Sequence {
    public:
        Sequence();

        // getters
        bool empty() const; 
        int size() const;
        bool get(int pos, ItemType& value) const;
        int find(const ItemType& value) const;

        void dump() const;

        // setters
        int insert(int pos, const ItemType& value);
        int insert(const ItemType& value);
        bool erase(int pos);
        int remove(const ItemType& value);
        bool set(int pos, const ItemType& value);
        void swap(Sequence& other);

    private: 
        ItemType array[DEFAULT_MAX_ITEMS];
        int length;
};

#endif /* SEQUENCE_H */