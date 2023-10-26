// sorts regular unordered array into an ordered heap

// O(nlog(n)) simple way
// 1. insert all n numbers into a new maxheap
// 2. while there are numbers left in heap:
//      a. remove biggest value from the heap
//      b. place it in the last open slot of the array

// O(nlog(n)) official way without extra space complexity
// 1. converting array into a maxheap O(n)
// 2. reheapify O(nlog(n))
// n + nlog(n) = nlog(n)

#include <iostream>

void heapify(int arr[], int size, int rootIndex) {
    int largestIndex = rootIndex;
    int leftChildIndex = 2 * rootIndex + 1;
    int rightChildIndex = 2 * rootIndex + 2;

    if (leftChildIndex < size && arr[leftChildIndex] > arr[largestIndex])
        largestIndex = leftChildIndex;

    if (rightChildIndex < size && arr[rightChildIndex] > arr[largestIndex])
        largestIndex = rightChildIndex;

    if (largestIndex != rootIndex) {
        std::swap(arr[rootIndex], arr[largestIndex]);
        heapify(arr, size, largestIndex);
    }
}

void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)  // start node: size/2 - 1 locates the right-most node in the tree that has at least one child
        heapify(arr, size, i);

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);         // Max heapify the reduced heap
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
