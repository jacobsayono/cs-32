#ifndef Sequence_h
#define Sequence_h

template<typename ItemType>
// using ItemType = unsigned long;

class Sequence
{
  public:
    Sequence();          // Create an empty sequence (i.e., one whose size() is 0).
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.

    int insert(int pos, const ItemType& value);
      // Insert value into the sequence so that it becomes the item at
      // position pos.  The original item at position pos and those that
      // follow it end up at positions one greater than they were at before.
      // Return pos if 0 <= pos <= size() and the value could be
      // inserted.  (It might not be, if the sequence has a fixed capacity,
      // e.g., because it's implemented using a fixed-size array.)  Otherwise,
      // leave the sequence unchanged and return -1.  Notice that
      // if pos is equal to size(), the value is inserted at the end.

    int insert(const ItemType& value);
      // Let p be the smallest integer such that value <= the item at
      // position p in the sequence; if no such item exists (i.e.,
      // value > all items in the sequence), let p be size().  Insert
      // value into the sequence so that it becomes the item in position
      // p.  The original item in position p and those that follow it end
      // up at positions one greater than before.  Return p if the value
      // was actually inserted.  Return -1 if the value was not inserted
      // (perhaps because the sequence has a fixed capacity and is full).

    bool erase(int pos);
      // If 0 <= pos < size(), remove the item at position pos from
      // the sequence (so that all items that followed that item end up at
      // positions one lower than they were at before), and return true.
      // Otherwise, leave the sequence unchanged and return false.

    int remove(const ItemType& value);
      // Erase all items from the sequence that == value.  Return the
      // number of items removed (which will be 0 if no item == value).

    bool get(int pos, ItemType& value) const;
      // If 0 <= pos < size(), copy into value the item at position pos
      // of the sequence and return true.  Otherwise, leave value unchanged
      // and return false.

    bool set(int pos, const ItemType& value);
      // If 0 <= pos < size(), replace the item at position pos of the
      // sequence with value and return true.  Otherwise, leave the sequence
      // unchanged and return false.

    int find(const ItemType& value) const;
      // Let p be the smallest integer such that value == the item at
      // position p in the sequence; if no such item exists, let p be -1.
      // Return p.

    void swap(Sequence& other);
      // Exchange the contents of this sequence with the other one.

      // Housekeeping functions
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& rhs);

  private:
      // Representation:
      //   a circular doubly-linked list with a dummy node.
      //   m_head points to the dummy node.
      //   m_head->m_prev->m_next == m_head and m_head->m_next->m_prev == m_head
      //   m_size == 0  iff  m_head->m_next == m_head->m_prev == m_head
      //   if m_size > 0
      //       m_head->next points to the node at position 0.
      //       m_head->prev points to the node at position m_size-1.

    struct Node
    {
        ItemType m_value;
        Node*    m_next;
        Node*    m_prev;
    };

    Node* m_head;
    int   m_size;

    void createEmpty();
      // Create an empty list.  (Should be called only by constructors.)

    void insertBefore(Node* p, const ItemType& value);
      // Insert value in a new Node before Node p, incrementing m_size.

    Node* doErase(Node* p);
      // Remove the Node p, decrementing m_size.  Return the Node that
      // followed p.

    Node* nodeAtPos(int pos) const;
      // Return pointer to Node at position pos.  If pos == m_size, return
      // m_head.  (Will be called only when 0 <= pos <= size().)
};

// Declarations of non-member functions
template<typename ItemType>
int subsequence(const Sequence<ItemType>& seq1, const Sequence<ItemType>& seq2);

template<typename ItemType>
void concatReverse(const Sequence<ItemType>& seq1, const Sequence<ItemType>& seq2, Sequence<ItemType>& result);


// Inline implementations
template<typename ItemType>
inline
int Sequence<ItemType>::size() const
{
    return m_size;
}
template<typename ItemType>
inline
bool Sequence<ItemType>::empty() const
{
    return size() == 0;
}

//
template<typename ItemType>
Sequence<ItemType>::Sequence()
{
    createEmpty();
}

template<typename ItemType>
Sequence<ItemType>::~Sequence()
{
      // Delete all Nodes from first non-dummy up to but not including
      // the dummy

    while (m_head->m_next != m_head)
        doErase(m_head->m_next);

      // Delete the dummy

    delete m_head;
}

template<typename ItemType>
Sequence<ItemType>::Sequence(const Sequence& other)
{
    createEmpty();

      // Copy all non-dummy other Nodes.  (This sets m_size.)
      // Inserting each new node before the dummy node that m_head points to
      // puts the new node at the end of the list.

    for (Node* p = other.m_head->m_next; p != other.m_head; p = p->m_next)
        insertBefore(m_head, p->m_value);
}

template<typename ItemType>
Sequence<ItemType>& Sequence<ItemType>::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

template<typename ItemType>
int Sequence<ItemType>::insert(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos > m_size)
        return -1;

    Node* p = nodeAtPos(pos);
    insertBefore(p, value);

    return pos;
}

template<typename ItemType>
int Sequence<ItemType>::insert(const ItemType& value)
{
      // Find the Node before which to insert
    Node* p;
    int pos;
    for (p = m_head->m_next, pos = 0; p != m_head  &&
                                value > p->m_value; p = p->m_next, pos++)
        ;

      // Insert the value there
    insertBefore(p, value);
    return pos;
}

template<typename ItemType>
bool Sequence<ItemType>::erase(int pos)
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    doErase(p);

    return true;
}

template<typename ItemType>
int Sequence<ItemType>::remove(const ItemType& value)
{
    int count = 0;

      // Walk through the list, erasing matching items

    Node* p = m_head->m_next;
    while (p != m_head)
    {
        if (p->m_value == value)
        {
                count++;
                p = doErase(p); // p now points to successor of erased Node
        }
        else
                p = p->m_next;  // p now points to successor of non-erased Node
    }
    return count;
}

template<typename ItemType>
bool Sequence<ItemType>::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    value = p->m_value;

    return true;
}

template<typename ItemType>
bool Sequence<ItemType>::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    p->m_value = value;

    return true;
}

template<typename ItemType>
int Sequence<ItemType>::find(const ItemType& value) const
{
      // Walk through the list, keeping track of position

    int pos = 0;
    Node* p = m_head->m_next;
    for ( ; p != m_head  &&  p->m_value != value; p = p->m_next, pos++)
        ;
    return p == m_head ? -1 : pos;
}

template<typename ItemType>
void Sequence<ItemType>::swap(Sequence& other)
{
      // Swap head pointers

    Node* p = other.m_head;
    other.m_head = m_head;
    m_head = p;

      // Swap sizes

    int s = other.m_size;
    other.m_size = m_size;
    m_size = s;
}

template<typename ItemType>
void Sequence<ItemType>::createEmpty()
{
    m_size = 0;

      // Create dummy node

    m_head = new Node;
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
}

template<typename ItemType>
void Sequence<ItemType>::insertBefore(Node* p, const ItemType& value)
{
      // Create a new node

    Node* newp = new Node;
    newp->m_value = value;

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp;
    newp->m_next->m_prev = newp;

    m_size++;
}

template<typename ItemType>
typename Sequence<ItemType>::Node* Sequence<ItemType>::doErase(Node* p)
{
      // Save pointer to p's successor

    Node* pnext = p->m_next;

      // Unlink p from the list and destroy it

    p->m_prev->m_next = p->m_next;
    p->m_next->m_prev = p->m_prev;
    delete p;

    m_size--;

    return pnext;
}

template<typename ItemType>
typename Sequence<ItemType>::Node* Sequence<ItemType>::nodeAtPos(int pos) const
{
    Node* p;

      // If pos is closer to the head of the list, go forward to find it.
      // Otherwise, start from tail and go backward.

    if (pos <= m_size / 2)  // closer to head
    {
        p = m_head->m_next;
        for (int k = 0; k != pos; k++)
            p = p->m_next;
    }
    else  // closer to tail
    {
        p = m_head;
        for (int k = m_size; k != pos; k--)
            p = p->m_prev;
    }

    return p;
}


template<typename ItemType>
int subsequence(const Sequence<ItemType>& seq1, const Sequence<ItemType>& seq2)
{
    if (seq2.empty())
        return -1;

      // Walk through seq1

    for (int pos = 0; pos <= seq1.size() - seq2.size(); pos++)
    {
          // Assume there's a match starting at pos

        bool allMatched = true;

          // Check if all corresponding positions match

        for (int k = 0; k < seq2.size(); k++)
        {
            ItemType v1;
            ItemType v2;
            seq1.get(pos+k, v1);
            seq2.get(k, v2);
            if (v1 != v2)
            {
                allMatched = false;
                break;
            }
        }

          // If we never found a mismatch, we've found the match.
        if (allMatched)
            return pos;
    }

      // If we never found a match, there is none.

    return -1;
}

template<typename ItemType>
void concatReverse(const Sequence<ItemType>& seq1, const Sequence<ItemType>& seq2, Sequence<ItemType>& result)
{
      // Guard against the case that result is an alias for seq1 or seq2
      // (i.e., that result is a reference to the same sequence that seq1 or
      // seq2 refers to) by building the answer in a local variable res.  When
      // done, swap res with result; the old value of result (now in res) will
      // be destroyed when res is destroyed.

    Sequence<ItemType> res;

    for (int k = seq1.size() - 1; k >= 0; k--)
    {
        ItemType v;
        seq1.get(k, v);
        res.insert(res.size(), v);
    }

    for (int k = seq2.size() - 1; k >= 0; k--)
    {
        ItemType v;
        seq2.get(k, v);
        res.insert(res.size(), v);
    }

    result.swap(res);
}

#endif /* Sequence_h */