// hash table: faster searching than BST but don't order elements alphabetically
// unordered set, unordered map

// close (linear probing) hash table: deleting is a problem
// open hash table: very good, must implement each bucket to point to linked list or tree

// efficiency depends on closed vs. open, how full hash table is, how many collisions


// load factor (L, where L = 0 means empty, L = 1 means full)
// L = (max # of values to insert) / (total buckets in the array)

// close hash
// avg # of tries = 0.5*(1 + 1/(1-L)) for L < 1.0

// open hash
// avg # of tries = 1 + L/2

// ex: 1.25 searches, up to 1000 items. how many buckets?
// checks = 1 + L/2
// 1.25 = 1 + (1000/x)/2

// always choose a prime number of buckets. causes even distribution and fewer collisions!

#include <iostream>
#include <vector>  // for traversing hash table in alphabetical order
#include <algorithm>  // sort() on stl vector

struct Bucket {
    // stores a value (e.g. ID #)
    int id;
    bool used;  // is bucket in-use?
};

const int NUM_BUCKETS = 10;  // if we know ahead of time there will be less than 10 id's to worry about

class HashTable {
    public:
        // INSERT (best case O(1), worst case O(n))
        void insert(int id) {
            int bucket = mapFunc(id);

            for (int tries = 0; tries < NUM_BUCKETS; tries++) {
                if (m_buckets[bucket].used == false) {  // if bucket is empty
                    m_buckets[bucket].id = id;
                    m_buckets[bucket].used = true;
                    return;
                }
                bucket = (bucket + 1) % NUM_BUCKETS;  // iterate to next bucket, go back to 0 after 9
            }
            // no room left in hash table
        }
        // SEARCH (best case O(1), worst case O(n))
        bool search(int id) {
            int bucket = mapFunc(id);

            for (int tries = 0; tries < NUM_BUCKETS; tries++) {
                if (m_buckets[bucket].used == false)
                    return false;
                if (m_buckets[bucket].id == id)  // found it
                    return true;

                bucket = (bucket + 1) % NUM_BUCKETS;
            }
            return false;  // not in hash table
        }
        // TRAVERSE/PRINT alphabetically, use a linear data structure: vector and use the sort() stl function
        void printItemsInOrder() {
            std::vector<int> items;

            for (int i = 0; i < NUM_BUCKETS; i++) {
                if (m_buckets[i].used) {
                    items.push_back(m_buckets[i].id);
                }
            }

            std::sort(items.begin(), items.end());  // O(nlog(n))

            for (int i = 0; i < items.size(); i++) {
                std::cout << items[i] << " ";
            }
            std::cout << std::endl;
        }
    private:
        // mapping function
        int mapFunc(int id) {
            int bucket = id % NUM_BUCKETS;
            return bucket;
        }
        Bucket m_buckets[NUM_BUCKETS];
};

int main() {
    HashTable ht;
    ht.insert(29);
    ht.insert(65);
    ht.insert(79);
}