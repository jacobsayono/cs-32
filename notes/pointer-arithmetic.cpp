#include <iostream>

void printData(int array[]);
void printDataNeg(int array[]);

void printData(int array[]) {
    std::cout << array[0] << std::endl;
    std::cout << array[1] << std::endl << std::endl;
}

void printDataNeg(int array[]) {
    std::cout << array[-1] << std::endl;
}

int main() {
    int nums[3] = {10, 20, 30};

    printData(nums);
    printData(&nums[1]);
    printData(nums+1);
    printDataNeg(nums+1);
}