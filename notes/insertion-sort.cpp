#include <iostream>

// O(n^2) worst case
// O(n) best case (if mostly already sorted)
// easily implemented for linked-list
// stable

void insertionSort(int A[], int n) {
    // start with first 2 elements, then 3...
    for (int s = 2; s <= n; s++) {
        // make a copy of the last element in current s
        int sortMe = A[s-1];

        // shift values in the focus region until we find the proper slot for sortMe
        int i = s - 2;
        while (i >= 0 && sortMe < A[i]) {
            A[i+1] = A[i];
            --i;
        }
        
        // store the sortMe value into the vacated slot
        A[i+1] = sortMe;
    }
}