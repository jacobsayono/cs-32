#include <iostream>

// singly linked list
struct Node {
    int value;

    // Node next;  // WRONG!!
    Node* next;
    
    // double linked list
    Node* prev;
};

int main() {
    Node* head;
    Node* p;

    // print out values in each node of a linked list
    for(p = head; p != nullptr; p = p->next) {
        std::cout << p->value << std::endl;
    }
    // say our linked list has nodes of values:
    // 47  23  18  42  36


    // find 18
    for (p = head; p != nullptr && p-> value != 18; p = p->next) {
        ;
    }
    // p now points to value 18 (after exiting for loop)
    // insert a 54 after the 18 in the list, if present
    if (p != nullptr) {
        // code to insert a 54 after the node that p points to
        Node* newGuy = new Node;
        newGuy->value = 54;
        newGuy->next = p->next;  // 54's next now points to 18's next which points to 42
        p->next = newGuy;  // 18's next points to 54

        // delete the 54 node
        Node* toBeDeleted = p->next;  // let this new node be 54 (18's next)
        p->next = p->next->next;  // or p->next = toBeDeleted->next;
        delete toBeDeleted;
    }

    // back of list can use newGuy method
    // let's say 18 is the end
    Node* z;
    z->next = p->next;
    delete p;

    // front of list is special case
    head = p->next;
    delete p;



    // doubly-linked list
    Node* head2;
    if (head2 != nullptr) {
        Node* oldHead = head2;
        head2 = head2->next;
        head2->prev = nullptr;
        delete oldHead;
    }

    // circular doubly-linked list with dummy node as first node (so no need for tail)
    // 10 30 20
    for (Node* p = head->next; p != head; p = p->next) {
        std::cout << p->value << std::endl;
    }
    // 20 30 10
    for (Node* p = head->prev; p != head; p = p->prev) {
        std::cout << p->value << std::endl;
    }
    

    return 0;
}

/*
draw pictures!
whenever you write p->... make sure
    p has a well-defined value (i.e., it's not uninitialized)
    p is not a nullptr

middle, front, back, empty, one-element list
*/