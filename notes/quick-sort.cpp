#include <algorithm>

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