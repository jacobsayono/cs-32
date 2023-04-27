#include <string>

struct Chest {
    std::string treasure;  // this is our "value"
    Chest* nextChest;  // this is our next "node", which hold a pointer to another Chest
};


int main() {
    Chest* head;  // create first every pointer
    Chest* second;
    Chest* third;

    // dynamically allocate chest structures using "new"
    head = new Chest;
    second = new Chest;
    third = new Chest;

    head->treasure = "toast";
    head->nextChest = second;

    second->treasure = "bacon";
    second->nextChest = third;

    third->treasure = "eggs";
    third->nextChest = nullptr;  // allows us to later check that the 3rd chest is our last chest

    Chest* address = head->nextChest;

    delete head;
    delete second;
    delete third;
}