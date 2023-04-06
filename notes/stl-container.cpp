#include <iostream>
#include <string>

#include <stack>
#include <queue>

#include <vector>  // dynamic arrays: like array but can push/pop elements one by one. fast access to any element (via brackets) but adding new items is often slower
#include <list>  // linked-lists: fast insertion/deletion, but slow to access middle elements

#include <map>  // associate 2 related values, alphabetical order, create operator< for own classes
#include <set>  // unique items only, ignores duplicate insertions, create operator< for own classes


// stack: push(x), pop(), top(), empty(), size()
// queue: push(x), pop(), front(), back(), empty(), size()

// vector: push_back(x), pop_back(x), front(), back(), empty(), size()
// list: push_back(x), push_front(x), pop_back(x), pop_front(x), front(), back(), empty(), size()
    // iterators: begin(), end(), find(begin(), end(), "vika") -> returns end() if not found, find_if(a, b, func)

// map: map_var[x] = y
// set: insert(x), erase(x), size()
    // iterators: find(), begin(), end()
    // bool operator<(const class &a, const class &b)

// iterator is invalidated once you add or erase items in a vector
// list, map, set, OK but don't erase item that iterator is pointing to

#include <algorithm>  // sort(first_it, second_it) a container to ascending order from begin to the element before end
// sort (&arr[0], &arr[4]);


void tick(const std::list<std::string> &nerds) {
        std::list<std::string>::const_iterator it3;  // use this keyword to iterate such container
        for (it3 = nerds.begin(); it3 != nerds.end(); it3++)
            std::cout << *it3 << "says teehee" << std::endl;
}

struct stud {
        std::string name;
        int id;
};

bool operator<(const stud &a, const stud &b) {
    // return (a.id < b.id);
    if (a.name == b.name) {
        return a.id < b.id;
    }
    return (a.name < b.name);
}

int main() {

    // stack
    std::stack<int> is;

    // queue
    std::queue<std::string> sq;

    is.push(5);
    is.push(10);

    sq.push("goober");




    // vector
    std::vector<int> vals(3);  // 0, 0, 0
    vals.push_back(123);  // 0, 0, 0, 123
    vals[0] = 42;  // 42, 0, 0, 3
    // vals[4] = 1998;  // crash
    std::cout << vals.back();  // 123
    std::cout << vals.front();  // 42

    vals.pop_back();  // 42, 0, 0
    vals.pop_back();  // 42, 0

    std::cout << vals.size();  // return current size = 2

    if (vals.empty() == false) {
        std::cout << "i have items!";
    }

    std::list<int> il;
    il.push_back(1);  // il -> 1
    il.push_back(2);  // il -> 1 -> 2
    il.push_front(3);  // il -> 3 -> 1 -> 2

    // il[0];  // cannot access elements; error!

    std::vector<int> vec;
    vec.push_back(1234);
    vec.push_back(5);
    vec.push_back(7);

    // iterator class for STL containers
    std::vector<int>::iterator it;
    std::list<int>::iterator itt;

    it = vec.begin();  // points to very first item in container
    std::cout << *it;  // operator overloading (dereference iterators)
    it++;  // points to next element in vector
    it--;  // go backwards
    it = vec.end();  // points to "null" or last item in vector
    it--;  // must iterate backward once first to get last item
    std::cout << *it;

    it = vec.begin();

    while(it != vec.end()) {  // when it points to "null" or the vec.end(), we know we've gone past the last item
        std::cout << *it;
        it++;
    }

    struct Thing {
        std::string first;
        int second;
        float third;
    };

    std::list<Thing> things;
    Thing d;
    d.first = "iluvC++";
    d.second = 300;
    d.third = 3.14;
    things.push_back(d);  // Thing is now ordered with first, second, third based on construction phase

    std::list<Thing>::iterator it2;
    it2 = things.begin();
    std::cout << it2->first;  // iluvc++

    std::list<std::string> nerds;
    nerds.push_back("cary");
    nerds.push_back("davi");
    tick(nerds);  // cary says teehee, davi says teehee





    // map
    std::map<std::string, int> name2phone;  // maps a string to an integer
    name2phone["cary"] = 818;
    name2phone["davi"] = 310;

    std::map<int, std::string> phone2name;
    phone2name[405] = "Ed";
    phone2name[812] = "Al";

    std::map<std::string, int>::iterator mapit;
    mapit = name2phone.find("cary");
    // default variable name map<first, second>
    std::cout << mapit->first;  // cary
    std::cout << mapit->second;  // 818

    mapit = name2phone.find("nowhere");  // automatically points iterator to the end()
    if (mapit == name2phone.end()) {
        std::cout << "not found" << std::endl;
    }


    std::map<stud, float> stud2GPA;  // since first is a class type, must create operator< to sort map
    stud sss;
    sss.name = "jacob";
    sss.id = 8811;

    stud2GPA[sss] = 4.0;



    // set
    std::set<int> a;
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(2);  // duplicate, so ignored
    std::cout << a.size();  // 3
    a.erase(4);  // now size is 2

    std::set<int>::iterator setit;
    setit = a.find(4);
    if (setit == a.end()) {
        std::cout << "4 was not found";
    }

}