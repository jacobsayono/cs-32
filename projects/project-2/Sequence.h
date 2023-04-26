#include <iostream>
#include <string>
#include <stdio.h>

#ifndef SEQUENCE_H
#define SEQUENCE_H

// using ItemType = std::string;
using ItemType = unsigned long;

class Sequence
{
    public:
        Sequence();  // constructor
        ~Sequence();  // destructor
        Sequence(const Sequence &other);  // copy constructor
        Sequence &operator=(const Sequence &rhs);  // assignment operator

        bool empty() const;
        int size() const;
        int insert(int pos, const ItemType &value);
        int insert(const ItemType &value);
        bool erase(int pos);
        int remove(const ItemType &value);
        bool get(int pos, ItemType &value) const;
        bool set(int pos, const ItemType &value);
        int find(const ItemType &value) const;
        void swap(Sequence &other);

    private:
        int m_size;

        // linked-list node
        struct Node
        {
            ItemType value;
            Node *next;
            Node *prev;
        };

        Node *head;
        Node *tail;

        void add_to_sequence(int pos, const ItemType &value);
        void addFront(const ItemType &value);
        void addRear(const ItemType &value);
        bool delete_element(int pos);
};

int subsequence(const Sequence &seq1, const Sequence &seq2);
void concatReverse(const Sequence &seq1, const Sequence &seq2, Sequence &result);

#endif /* SEQUENCE_H */