#ifndef NEWSEQUENCE_H
#define NEWSEQUENCE_H

using ItemType = unsigned long;
const int DEFAULT_MAX_ITEMS = 160;

class Sequence {
  public:
    Sequence();
    Sequence(int maxSize);
    ~Sequence();   // destructor
    Sequence(const Sequence& seq);   // copy constructor
    Sequence& operator=(const Sequence& seq);    // assignment operator

    bool empty() const;
    int size() const;
    bool get(int pos, ItemType& value) const;
    int find(const ItemType& value) const;

    void dump() const;
    
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool set(int pos, const ItemType& value);
    void swap(Sequence& other);

  private:
    ItemType* array;
    int length;
    int max_length;
};

#endif