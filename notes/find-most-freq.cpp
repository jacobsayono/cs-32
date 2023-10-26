#include <iostream>
#include <unordered_map>

int findMostFrequentElement(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;
    int leftMostFrequent = findMostFrequentElement(arr, left, mid);
    int rightMostFrequent = findMostFrequentElement(arr, mid + 1, right);

    // Count the frequency of the left and right most frequent elements
    std::unordered_map<int, int> frequencyMap;
    frequencyMap[leftMostFrequent]++;
    frequencyMap[rightMostFrequent]++;

    // Determine which element occurs more frequently
    int mostFrequentElement;
    if (frequencyMap[leftMostFrequent] > frequencyMap[rightMostFrequent]) {
        mostFrequentElement = leftMostFrequent;
    } else {
        mostFrequentElement = rightMostFrequent;
    }

    return mostFrequentElement;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int mostFrequent = findMostFrequentElement(arr, 0, size - 1);

    std::cout << "Most frequent element: " << mostFrequent << std::endl;

    return 0;
}
