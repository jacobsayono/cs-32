#include <iostream>

void swap(int* p_a, int* p_b);

void swap(int* p_a, int* p_b) {
    int temp;
    temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
    // temp goes away after leaving function
    // p_a and p_b too
}

int main() {
    int a = 5, b = 6;
    swap(&a, &b);
    std::cout << a << std::endl << b << std::endl;
}