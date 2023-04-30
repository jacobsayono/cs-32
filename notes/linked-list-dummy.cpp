#include <string>

struct Node {
    std::string value;
    Node* next;
};

class LinkedList {
    public:
        LinkedList() {
            dummy.next = nullptr;
            dummy.value = "";  // dummy node holds no value, but it is a node
        }
        void deleteItem(std::string v) {
            // if empty
            if (dummy.next == nullptr) {
                return;
            }

            // if not empty, traverse to desired target
            Node* p = &dummy;
            while (p != nullptr) {
                if (p->next != nullptr && p->next->value == v) {
                    break;
                }
                p = p->next;
            }

            // target node at least exists
            if (p != nullptr) {
                Node* killMe = p->next;
                p->next = p->next;
                delete killMe;
            }
        }
    private:
        Node dummy;  // regular node, NOT a pointer
};