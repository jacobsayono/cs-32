#include <iostream>
#include <string>

// of course, with doubly linked list,
// we have to link up lots of additional pointers...
// but this gives us an option to traverse backwards in the list!

struct Node {
    std::string value;

    Node* next;
    Node* prev;
};

class LinkedList {
    public:
        LinkedList();
        void traverseForward();
        void traverseBackward();

    private:
        Node* head;
        Node* tail;
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::traverseForward() {
    Node* p = head;
    while (p != nullptr) {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}

void LinkedList::traverseBackward() {
    Node* p = tail;
    while (p != nullptr) {
        std::cout << p->value << std::endl;
        p = p->prev;
    }
}