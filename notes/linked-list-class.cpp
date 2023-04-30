#include <string>
#include <iostream>

struct Node {
    std::string value;
    Node* next;
};

class LinkedList {
    public:
        LinkedList();
        void addToFront(std::string v);
        void addToRear(std::string v);
        void addToRearWithTail(std::string v);
        void addToMiddle(std::string v, std::string beforeThisGuy);
        void deleteItem(std::string v);
        bool findItem(std::string v);
        void printItems();
        ~LinkedList();

    private:
        Node* head;
        Node* tail;
};

LinkedList::LinkedList() {
    head = nullptr;  // create an "empty" linked list
}

void LinkedList::printItems() {
    Node *p;  // create a temporary pointer p
    p = head;  // set p's value equal to the value of the head pointer
    // so both p and head pointer point at the first node

    while (p != nullptr) {  // loops until p is equal to nullptr, i.e., the end of the list, so we know it's time to stop
        std::cout << p->value << std::endl;  // prints out the value in the current node pointed to by p
        p = p->next;  // works like i++. p advances to next node
    }
}

void LinkedList::addToFront(std::string v) {
    Node* p;
    p = new Node;  // allocates an empty node to hold our new item that is to be added
    p->value = v;  // sets whatever string you want to store as this node's value

    p->next = head;  // links our new node to the same address that head holds (that is pointing to), which is the first item in the list

    head = p;  // makes our head pointer point to the newly created node, so it's the first one on the list (so now we have p and head pointers pointing to the front, our new node)

    // if the LinkedList is empty, it still works the same because head points to nullptr
    // and we add our new node, with p pointing to it
    // so the end of the new node points to nullptr when we set it equal to the head pointer
    // and just change head pointing from nullptr to the address of the new node
}

void LinkedList::addToRear(std::string v) {
    // case 1: list is empty
    if (head == nullptr) {
        addToFront(v);  // which basically add's to the back
    }

    // case 2: list has 1 or more nodes
    else {
        Node* p;  // create a traversing pointer that goes right before nullptr (which is the last item on the list)
        p = head;
        while (p->next != nullptr) {
            p = p->next;
        }

        // now that we have set p's "position" to be pointing to the end of the list

        Node* n = new Node;  // create the new node we want to add to the back
        n->value = v;  // set the value to whatever string we want to add into the list

        p->next = n;  // link the last node to our new node by changing from pointing to nullptr to pointing to our new node
        
        n->next = nullptr;  // set the added node to point to the nullptr since it's the last item now
    }
}

void LinkedList::addToRearWithTail(std::string v) {
    if (head == nullptr) {
        addToFront(v);  // if empty list
    }
    else {
        Node* n = new Node;  // create new node to add
        n->value = v;  // set the node's value
        tail->next = n;  // set current tail node's next pointer equal to the location of our new node
        n->next = nullptr;  // set our new node's next pointer to nullptr, so it becomes the new last node in the linked list
        tail = n;  // change out pointer so it points at our new last node
    }
}

void LinkedList::addToMiddle(std::string v,  std::string beforeThisGuy) {
    // if list is empty
    if (head == nullptr) {
        addToFront(v);
    }

    else {
        Node *p = head;  // start with top node
        while (p->next != nullptr) {
            if (p->value == beforeThisGuy) {
                break;
            }
            p = p->next;  // move down one node
        }

        Node* latest = new Node;  // alloc and fill our new node
        latest->value = v;
        latest->next = p->next;  // link new node to p's original next node
        p->next = latest;  // link p's new next node to the node we added
    }
}

void LinkedList::deleteItem(std::string v) {
    // case 1: deleting first node
    if (head == nullptr) {
        return;  // do nothing if empty list
    }

    if (head->value == v) {  // checking if target node is the first node, which head points to
        Node* killMe = head;  // killMe points to top node we want to delete
        head = killMe->next;  // change head pointer to point to the second node
        delete killMe;  // delete the node pointed to by KillMe pointer
        return;
    }

    // case 2: delete interior or last node
    Node* p = head;  // create a traversing pointer
    while (p != nullptr) {  // traverse until it finds the node we want to delete
        if (p->next != nullptr && p->next->value == v) {  // if the address of that node is not nullptr and the value of that node is our target string
            // first check that there is the node we want to delete, and stop before it if there is
            // when we find the target value in p->next->value, then p will stop at the node just above the node we want to delete
            break;  // p points to node above
        }
        p = p->next;
    }

    // so now we know there is a node to delete, and p is pointing to the node just before the node to be deleted
    if (p != nullptr) {
        Node* killMe = p->next;  // since the node to be deleted is right after p
        p->next = killMe->next;  // link p's next value (address) to point to the node that skips after the node to be deleted
        delete killMe;  // delete our target node
    }

}

bool LinkedList::findItem(std::string v) {
    bool ret_value;
    // create a traversing pointer that starts at the head
    Node* t = head;
    while (t != nullptr) {
        if (t->value == v) {
            ret_value = true;
            break;
        }
        t = t->next;
    }
    if (t == nullptr) {
        ret_value = false;
    }
    return ret_value;
}

// delete each node one by one
LinkedList::~LinkedList() {
    Node* p = head;  // this pointer will traverse
    while (p != nullptr) {
        Node* n = p->next;  // gets a pointer to the node after the current one is pointed at by p, so we don't forget where it is
        delete p;  // delete the node that p points to
        p = n;  // now pointer p points to the node after the one that was just deleted, and continute deleting
    }
}

int main() {
    LinkedList myFriends;
    myFriends.addToFront("Jacob");
    myFriends.addToRear("David");
    myFriends.addToMiddle("Carey", "David");

    myFriends.printItems();

    if (myFriends.findItem("Carey") == true) {
        std::cout << "I'm so lucky!" << std::endl;
    }
}