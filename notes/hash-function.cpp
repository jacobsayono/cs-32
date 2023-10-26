#include <string>

int mapFunc(int id) {
    return id % 100000;
}

int mapFunc(std::string &name) {
    int h = hash(name);
    return h % 100000;
}

int hash(const std::string &name) {
    int i, total = 0;
    for (i = 0; i < name.length(); i++) {
        total = total + (i+1) * name[i];  // BAT vs TAB will have different int assignment
    }
    return total;
}

#include <functional>
unsigned int myMapFunc(const std::string &hashMe) {
    std::hash<std::string> str_hash;  // creates a string hasher "function"
    unsigned int hashValue = str_hash(hashMe);  // now hash our string
    // hashValue will return between 0 and 4 billion

    // add our own modulo to fit into our hash table array
    unsigned int bucketNum = hashValue % 10000;
    return bucketNum;
}

// hash function must always give us the same output for a given input
// hash function should disperse items throughout the hash array as randomly as possible
// always measure how well it disperses items