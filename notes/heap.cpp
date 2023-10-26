// heap: tree-based data structure used to implement priority queues to do efficient sorting*
// two types: minheaps, maxheaps
// minheaps: smallest item is at the root
// maxheaps: largest item is at the root

// uses a binary tree to store data, but NOT a binary search tree
// clever use of an array to implement the binary tree. O(log(n)) to keep proper item at the top when insert/remove items

// all heaps use a "COMPLETE BINARY TREE":
// all the top n-1 levels of the tree are completely filled with nodes
// all bottom-most level nodes must be as far left as possible (no empty slots between nodes)

// O(log(n)) can quickly insert/extract a item into the heap, best and worst case!
// O(1) can quickly access the largest (in maxheap) or the smallest (in minheap)
// but remember to reorder tree so that it is till a CBT (reheapification is what causes log(n))

// higher level node must be >= than the 2 children nodes (in maxheap, vice versa <= for minheap)

// extracting largest value in maxheap:
// if tree is empty, return error
// otherwise, take value out from root (since it's maxheap)
// find bottom-most right-most node value, copy to root position
// delete that node
// repeatedly sift down by swapping with the larger of 2 children until the value is >= to BOTH its children

// adding node to maxheap:
// if tree is empty, create new root node & return
// otherwise, insert new node to bottom-most left-most position of tree
// compare new value with its parent's value
// if new value is greater than parent's value, swap
// keep comparing and swapping until new value rises to its proper place

// reordering the heap (complete binary tree) is called reheapification

// implementing a heap: use an array!
// array-based tree (heap)
// root is always at heap[0]
// bottom-most, right-most at heap[node_count-1]
// bottom-most, left-most at heap[node_count]
// add/replace/remove node by simply setting heap[count] = value or updating count

// heap location of left and right children node:
// leftChild(parent) = 2*parent + 1
// rightChild(parent) = 2*parent + 2

// parent = (child-1)/2
// use integer division

// trinary:
// 3*parent + 1
// 3*parent + 2
// 3*parent + 3
// (child-1)/3

#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> data;

    void heapifyUp(int index) {
        if (index <= 0)
            return;

        int parentIndex = (index - 1) / 2;
        if (data[parentIndex] < data[index]) {
            std::swap(data[parentIndex], data[index]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftChildIndex < data.size() && data[leftChildIndex] > data[largestIndex])
            largestIndex = leftChildIndex;

        if (rightChildIndex < data.size() && data[rightChildIndex] > data[largestIndex])
            largestIndex = rightChildIndex;

        if (largestIndex != index) {
            std::swap(data[index], data[largestIndex]);
            heapifyDown(largestIndex);
        }
    }

public:
    void insert(int item) {
        data.push_back(item);
        heapifyUp(data.size() - 1);
    }

    int remove() {
        if (data.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int root = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        heapifyDown(0);

        return root;
    }

    bool empty() const {
        return data.empty();
    }
};

int main() {
    Heap maxHeap;

    maxHeap.insert(4);
    maxHeap.insert(9);
    maxHeap.insert(2);
    maxHeap.insert(7);

    while (!maxHeap.empty()) {
        std::cout << maxHeap.remove() << " ";
    }
    std::cout << std::endl;

    return 0;
}
