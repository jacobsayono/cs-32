#include <algorithm>  // std::swap()

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