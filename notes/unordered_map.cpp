#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

// unordered_map: hash-based version of a map

int main() {
    unordered_map<string, int> hashmap;  // define a new UM
    unordered_map<string, int>::iterator i;  // define iterator for UM
    
    hashmap["jacob"] = 10;  // insert a new item into UM
    hashmap["vika"] = 20;

    i = hashmap.find("jacob");  // find jacob in the hashmap

    if (i == hashmap.end())
        cout << "jacob was not found";
    else {
        cout << "when we search for " << i->first;  // when we search for jacob
        cout << " we find " << i->second;  // we find 10
    }
}

// remember that hash table and hash map are not ordered (random/disperse)