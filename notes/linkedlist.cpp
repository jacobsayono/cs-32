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

• Draw pictures! In many places in the code, you will be creating or deleting nodes and retargeting
where a pointer variable points to. If you look at just the code, it's hard to understand what's
going on, so it's easy for mistakes to go unnoticed. Draw a picture of the list and trace through
the code carefully, updating the picture as you go along in accordance with what the code actually
says to do, not what you wish it did. It's amazing how many bugs you catch this way.

• Anytime you write p->something, make sure that you can prove to yourself that no matter
how you get to that point,
    o p has previously been given a value
    o p's value is not the null pointer

• Make sure that code that inserts or removes or examines items in a list works correctly
    o for activity in the typical case: somewhere in the middle of the list
    o for activity at the front of the list
    o for activity at the end of the list
    o for an empty list
    o for a one-element list (usually, but not always, this case is covered by some of the others)

• When doing something that changes several pointers (e.g., inserting, removing, or rearranging
nodes), make sure you execute the statements changing the pointers in the right order; don't lose a
pointer value that you need later. When creating a new node, one thing that helps is setting its
pointer members before changing other pointers: Those members have no old value that you
might need later, and by setting them first, you reduce the number of ways to mis-order the
remaining pointer manipulations.

*/