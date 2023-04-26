#include "Sequence.h"

Sequence::Sequence() {
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

Sequence::~Sequence() {
    Node* p;
    p = head;
    while (p != nullptr) {
        Node* n = p->next;
        delete p;  // delete all nodes
        p = n;
    }
}

Sequence::Sequence(const Sequence &other) {
    if (other.head == nullptr) {  // check to see if list is empty
        head = nullptr;
        tail = nullptr;
        m_size = 0;
    }
    else {
        head = nullptr;  // make empty list
        tail = nullptr;
        m_size = 0;
        ItemType p;
        for (int i = 0; i < other.m_size; i++) {  // add elements to the list
            other.get(i, p);
            addRear(p);
        }
        m_size = other.m_size;
    }
}

Sequence &Sequence::operator=(const Sequence &rhs) {
    if (this != &rhs) {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

int Sequence::size() const {
    return m_size;
}

bool Sequence::empty() const {
    return (m_size == 0);
}

int Sequence::insert(int pos, const ItemType &value) {
    // invalid case
    if (pos < 0 || pos > size()) {
        return -1;
    }

    else if (pos == 0) {  // add to front
        addFront(value);
    }

    else if (pos == size()) {  // ad to back
        addRear(value);
    }

    else {
        add_to_sequence(pos, value);
    }

    return pos;
}

int Sequence::insert(const ItemType &value) {

    if (head == nullptr) {
        addFront(value);  // add to front
    }

    // checking to make sure that it is less and adds to the front of first element
    else if (head->value >= value) {
        addFront(value);
        return 0;
    }

    // add to the rest of list
    else {
        Node* p;
        int counter = 1;
        for (p = head; p != nullptr && p->next != nullptr && value > p->next->value; p = p->next)
            counter++;
        add_to_sequence(counter, value);
        return counter;
    }
    return 0;
}

bool Sequence::erase(int pos) {
    // checks if correct pos
    if (pos < 0 || pos >= size()) {
        return false;
    }
    // verifies nullptr, cannot erase if head is not nullptr
    if (head == nullptr) {
        return false;
    }

    return (delete_element(pos));
}

int Sequence::remove(const ItemType &value) { // removes all variables that are in sequence defined
    if (head == nullptr) {
        return 0;
    }

    Node* p = head;
    int counter = 0;
    int pos = 0;

    while (p != nullptr) {
        if (p->value == value) {
            p = p->next;
            erase(pos);  // if we find match, delete and increment
            counter++;
            pos--;
        }
        else {
            p = p->next;
        }
        pos++;
    }

    return counter;
}

bool Sequence::get(int pos, ItemType &value) const { // get value from pos and store into item type
    // check for invalid
    if (pos < 0 || pos >= size()) {
        return false;
    }

    // check for empty
    if (head == nullptr) {
        return false;
    }

    Node* m;
    int counter = 0;
    for (m = head; m != nullptr; m = m->next) {  // locate the position and get p to point to it
        if (counter == pos) {
            value = m->value; // copy the value
            return true;
        }
        counter++;
    }

    return false;
}

bool Sequence::set(int pos, const ItemType &value) {
    // check for invalid
    if (pos < 0 || pos >= size()) {
        return false;
    }

    // checks for empty set (memory leak causer)
    if (head == nullptr) {
        return false;
    }

    Node* m;
    int counter = 0;
    
    for (m = head; m != nullptr; m = m->next) {  // locate the position and get p to point at it
        if (counter == pos)
            break;
        counter++;
    }
    m->value = value; // copy the value
    return true;
}

int Sequence::find(const ItemType &value) const {
    Node* p;
    int counter = 0;
    for (p = head; p != nullptr; p = p->next) {
        if (p->value == value)
            return counter;
        counter++;
    }
    return -1;
}

void Sequence::swap(Sequence &other) {
    // copy over the private variables
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
    // copy over the sequences
    // stores the pointers into something else
    Node* p = head;
    Node* m = tail;

    //
    head = other.head;
    tail = other.tail;

    other.head = p;
    other.tail = m;
}

void Sequence::addFront(const ItemType &value) {
    Node* p;
    p = new Node;
    p->value = value;

    // empty
    if (head == nullptr) {
        // fill node
        p->next = head;
        p->prev = nullptr;
        head = p;
        tail = p;
    }
    else {
        p->next = head;
        p->prev = nullptr;
        p->next->prev = p;
        head = p;
    }

    m_size++;
}

void Sequence::addRear(const ItemType &value) {
    // checks if the sequence is empty
    if (head == nullptr || tail == nullptr) {
        addFront(value);
    }
    else {
        // fill in node
        Node* n;
        n = new Node;
        n->value = value;
        // alter linking
        n->next = nullptr;
        n->prev = tail;
        tail->next = n;
        tail = n;

        m_size++;
    }
}

void Sequence::add_to_sequence(int pos, const ItemType &value) {
    Node* p = head;
    int counter = 0;

    while (p != nullptr) {
        if (counter == pos - 1)
            break;
        counter++;
        p = p->next;
    }

    // checks if on last element
    if (p->next == nullptr) {
        addRear(value);
    }
    else {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = p->next;
        if (new_node->next->prev != nullptr)
            new_node->next->prev = new_node;
        new_node->prev = p;
        p->next = new_node;
        m_size++;
    }
}

bool Sequence::delete_element(int pos) {
    if (pos == 0) {
        if (m_size > 1) {
            Node* to_be_deleted = head;
            head = to_be_deleted->next;
            to_be_deleted->next->prev = nullptr;  // first item in the list points prev to nullptr
            delete to_be_deleted; // delete
            m_size--;
            return true;
        }
        else {
            Node *to_be_deleted = head;
            head = to_be_deleted->next;
            to_be_deleted->prev = nullptr;  // by itself
            delete to_be_deleted;    // delete
            m_size--;
            return true;
        }
    }

    else {
        int counter = 0;
        Node* p = head;
        while (p != nullptr) {
            if (counter == pos - 1)
                break;
            counter++;
            p = p->next;
        }
        if (p->next->next != nullptr) {
            Node* to_be_deleted = p->next;
            p->next = to_be_deleted->next;
            to_be_deleted->next->prev = to_be_deleted->prev;
            delete to_be_deleted;
            m_size--;
            return true;
        }
        else if (p->next->next == nullptr) {  // last element in the entire list
            Node* to_be_deleted = p->next;
            p->next = nullptr;
            tail = p;
            delete to_be_deleted;
            m_size--;
            return true;
        }
    }
    return false;
}

int subsequence(const Sequence &seq1, const Sequence &seq2) {
    ItemType value1;
    ItemType head2;
    ItemType value2;

    // sets initial defualt return
    int return_val = -1;

    seq2.get(0, head2);
    for (int i = 0; i < seq1.size(); i++) {  // loop through entire sequence and get the value
        seq1.get(i, value1);

        if (value1 == head2) {
            int counter = 0;
            for (int j = 0; j < seq2.size(); j++) {  // match every position if seq1 and seq2 same length
                seq1.get((i + j), value1);
                seq2.get(j, value2);
                if (value1 == value2) { // check subseq values
                    counter++;
                }

                if (counter == seq2.size()) {
                    return_val = i;
                }
            }
        }
    }
    return return_val;
}

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
    // alias protection
    Sequence temp;

    // case 1: both empty
    if (seq1.empty() && seq2.empty()) {
        result = temp;
        return;  // done
    }

    // case 2: seq1 empty
    int res = 0;
    if (seq1.empty()) {
        for (int pos = seq2.size() - 1; pos >= 0; pos--) {
            ItemType data; // reverse seq2 and append to temp
            seq2.get(pos, data);
            temp.insert(res, data);
            res++;
        }
        result = temp;  // assign temp to result
    }

    // case 3: seq2 empty
    else if (seq2.empty()) {
        for (int pos = seq2.size() - 1; pos >= 0; pos--) {
            ItemType data;  // reverse seq1 and append to temp
            seq1.get(pos, data);
            temp.insert(res, data);
            res++;
        }
        result = temp;  // assign temp to result
    }

    // case 4: both not empty
    else {
        for (int pos1 = seq1.size() - 1; pos1 >= 0; pos1--) {
            ItemType data;  // reverse seq1 and append to temp
            seq1.get(pos1, data);
            temp.insert(res, data);
            res++;
        }
        for (int pos2 = seq2.size() - 1; pos2 >= 0; pos2--) {
            ItemType data;  // reverse seq2 and append to temp
            seq2.get(pos2, data);
            temp.insert(res, data);
            res++;
        }
        result = temp;  // done
    }
}