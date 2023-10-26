// n + n-1 + n-2 + ... + 2 + 1
// O(n^2)
// unstable
// uses swap(), not easy for linked-list

#include <algorithm>  // std::swap()
#include <iostream>

void selectionSort(int A[], int n) {
    // for each of the n array elements
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        // locate the smallest item in array between i and n-i
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;  // replace minIndex to j, and keep looping through entire array until minIndex equals the index that holds the smallest possible element
            }
        }
        // swap smallest item found with slow A[i]
        std::swap(A[i], A[minIndex]);
    }
}

int main() {
    int n = 5;
    int array[n] = {5, 2, 3, 4, 1};
    selectionSort(array, n);
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
}