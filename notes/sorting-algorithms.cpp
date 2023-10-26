#include <algorithm>  // std::swap()
#include <iostream>


// n + n-1 + n-2 + ... + 2 + 1
// O(n^2)
// unstable
// uses swap(), not easy for linked-list
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



// O(n^2)
// O(n) best case (if already mostly sorted)
// stable
// uses swap(), somewhat medium to implement into linked-list
void bubbleSort(int Arr[], int n) {
    bool atLeastOneSwap;

    do {
        atLeastOneSwap = false;
        for (int j = 0; j < (n-1); j++) {
            if (Arr[j] > Arr[j+1]) {
                std::swap(Arr[j], Arr[j+1]);
                atLeastOneSwap = true;
            }
        }
    } while (atLeastOneSwap == true);
}



// O(nlog(n))
// worst case: O(n^2)
// unstable
void quickSort(int a[], int first, int last) {
    if (last - first >= 1) {
        int pivotIndex = Partition(a, first, last);
        quickSort(a, first, pivotIndex-1);  // left
        quickSort(a, pivotIndex+1, last);
    }
}
int Partition(int a[], int low, int high) {
    // select first item as our pivot value
    int pi = low;
    int pivot = a[low];
    do {
        // find first value > than the pivot
        while (low <= high && a[low] <= pivot) {
            low++;
        }
        // find first value <= than the pivot
        while(a[high] > pivot) {
            high--;
        }
        // swap the larger with the smaller
        if (low < high) {
            std::swap(a[low], a[high]);
        }
    } while (low < high);

    // swap pivot to proper position in array
    std::swap(a[pi], a[high]);
    pi = high;

    return(pi);
}



int main() {
    int n = 5;
    int array[n] = {5, 2, 3, 4, 1};
    selectionSort(array, n);
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
}