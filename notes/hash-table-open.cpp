#include <iostream>

struct Node {
    int id;
    Node* next;
};

const int NUM_BUCKETS = 10;

class HashTable {
public:
    // Constructor
    HashTable() {
        m_buckets = new Node[NUM_BUCKETS]();
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < NUM_BUCKETS; i++) {
            Node* current = m_buckets[i].next;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] m_buckets;
    }

    // INSERT (best case O(1), worst case O(n))
    void insert(int id) {
        int bucket = mapFunc(id);

        Node* newNode = new Node;
        newNode->id = id;
        newNode->next = nullptr;

        if (m_buckets[bucket].next == nullptr) {
            // Bucket is empty, add new node as the first element
            m_buckets[bucket].next = newNode;
        } else {
            // Bucket already has elements, add new node at the end
            Node* current = m_buckets[bucket].next;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // SEARCH (best case O(1), worst case O(n))
    bool search(int id) {
        int bucket = mapFunc(id);

        Node* current = m_buckets[bucket].next;
        while (current != nullptr) {
            if (current->id == id) {
                return true; // Found it
            }
            current = current->next;
        }
        return false; // Not in hash table
    }

private:
    // Mapping function
    int mapFunc(int id) {
        int bucket = id % NUM_BUCKETS;
        return bucket;
    }

    Node* m_buckets;
};

int main() {
    HashTable ht;
    ht.insert(29);
    ht.insert(65);
    ht.insert(79);

    std::cout << "Searching for 29: " << (ht.search(29) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 65: " << (ht.search(65) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 79: " << (ht.search(79) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 42: " << (ht.search(42) ? "Found" : "Not Found") << std::endl;

    return 0;
}
