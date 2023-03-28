template <typename Data>
void swap(Data &x, Data &y) {
    // Data temp = Data(x);  // Direct initialization using copy constructor (use this if we don't have copy constructor)
    Data temp = x;
    x = y;
    y = temp;
}

template<typename Item>
class Dog {
    public:
        Dog(Item weight) {
            m_weight = weight;
        }
        Dog(const Dog& other) : m_weight(other.m_weight) {}
        Item weight() const {
            return m_weight;
        }
        bool operator>(const Dog& other) const {
            return m_weight > other.m_weight;
        }
    private:
        Item m_weight;
};

// template<typename Item>
// bool operator>(const Dog<Item> &a, const Dog<Item> &b) {
//     return a.weight() > b.weight();
// }

class Cat {
    public:
        Cat(int weight) {
            m_weight = weight;
        }
        Cat(const Cat& other) : m_weight(other.m_weight) {}
        int weight() const {
            return m_weight;
        }
        bool operator>(const Cat& other) const {
            return m_weight > other.m_weight;
        }
    private:
        int m_weight;
};

template <typename Item>
class HoldOneValue {
    public:
        void setVal(Item a) {
            m_a = a;
        }
        void printThreeTimes() {
            for (int i = 0; i < 3; i++) {
                std::cout << m_a << std::endl;
            }
        }
    private:
        Item m_a;
};

template<typename Type1, typename Type2>
void foo(Type1 a, Type2 b) {
    Type1 temp;
    Type2 array[3];
    temp = a;
    array[0] = b;
}

template<typename Item>
class External {
    public:
        void setVal(Item a);
        void printVal() const;
    private:
        Item m_a;
};

template<typename Item>
void External<Item>::setVal(Item a) {
    m_a = a;
}

template<typename Item>
void External<Item>::printVal() const {
    std::cout << "m_a" << std::endl;
}




template <class HoldMe>
class LinkedList {
    public:
        LinkedList() {
            head = nullptr;
        }
        bool ins(HoldMe value) {
            return true;
        }
        // bool del(HoldMe value);
        // bool retrieve(int i, HoldMe &value);
        // int size();
        ~LinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }
    private:
        class Node {
            public:
                HoldMe data;
                Node* next;
                Node (const HoldMe &value) :data(value), next(nullptr) {}
        };

        Node* head;
};