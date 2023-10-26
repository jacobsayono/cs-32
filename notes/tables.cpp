// tables: store a bunch of "records" (e.g. student info) and provide multiple ways to search for an item
// e.g. can search by id, name, phone

// so far, hash table & binary search tree enables searching efficiently by a single field type

// table ADT: we can store full record (name, id , gpa) just once
// then create multiple light "indices" (e.g. using HT/BST) to speed up searching by different field types

// record: a group of related data (box)
// fields: name, id, gpa (stuff)
// table: bunch of records (bunch of boxes)

// can have same name or birthday sometimes, but fields like SSN are unique across all records (useful!)
// key field: unique value across all records

// secondary map can be a BST or Hash Table
// BST: names, if want to print alphabetically
// Hash Table: number, if want O(1) search

/*
Hash Table Search:
Best Case: O(1) - If there are no collisions and the hash function provides a uniform distribution, the search can be performed in constant time.
Average Case: O(1) - With a well-designed hash function and a sufficiently low load factor, the average case time complexity for search operations in a hash table remains constant.
Worst Case: O(n) - In the worst case, all the keys collide and end up in the same bucket, resulting in a linear search through the elements in that bucket. This happens rarely but can occur if the hash function is poor or the load factor is high.

Binary Tree Search:
Best Case: O(1) - If the element being searched is at the root of a balanced binary tree, the search operation can be performed in constant time.
Average Case: O(log n) - In a balanced binary tree, the average case time complexity for search operations is logarithmic to the number of elements in the tree. It is due to the balanced nature of the tree, which ensures a roughly equal number of elements on both sides of each node.
Worst Case: O(n) - In the worst case, when the binary tree is heavily unbalanced (e.g., degenerates into a linked list), the search operation will require traversing through all n elements, resulting in a linear search.
*/

#include <vector>
#include <map>
#include <string>

struct Student {
    std::string name;
    int id;
    float gpa;
    int phone;
};

class TableOfStudents {
    public:
        TableOfStudents();
        ~TableOfStudents();
        void addStudent(Student &stud);  // add a new Student
        // if want to delete record or update record's searchable fields, we also have to update our indexes!! (the secondary maps)
        Student getStudent(int s);  // retrieve Students from slot s
        int searchByName(std::string &findname);
        int searchByPhone(int findphone);
    private:
        std::vector<Student> m_students;
        // secondary data structures "indexes"
        std::map<std::string, int> m_nameToSlot;  // second int is for the array (table)
        std::map<int, int> m_idToSlot;
};

void TableOfStudents::addStudent(Student &stud) {
    m_students.push_back(stud);  // vector of students
    int slot = m_students.size() - 1;  // get slot # of new record
    // each node in the BST is a map of name/id to slot #
    m_nameToSlot[stud.name] = slot;  // maps name to slot #
    m_idToSlot[stud.id] = slot;  // maps id to slot #
}

int TableOfStudents::searchByName(std::string &findname) {
    for (int s = 0; s < m_students.size(); s++) {
        if (findname == m_students[s].name) {
            return s;  // the student we're looking for is in slot s
        }
    }
    return -1;  // did not find student in table
}

int TableOfStudents::searchByPhone(int findphone) {
    for (int s = 0; s < m_students.size(); s++) {
        if (findphone == m_students[s].phone) {
            return s;  // the student we're looking for is in slot s
        }
    }
    return -1;  // did not find student in table
}

int main() {
    std::vector<Student> table;
}
