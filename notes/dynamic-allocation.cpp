#include <iostream>

class PiNerd {
    public:
        PiNerd() {
            for (int j = 0; j < 3; j++) {
                m_pi[j] = getPiDigit(j);
            }
        }
        void showOff() {
            for (int j = 0; j < 3; j++) {
                std::cout << m_pi[j] << std::endl;
            }
        }
        int getPiDigit(int j) {
            return 3;
        }
    
    private:
        int m_pi[3];
};

class PiNerdDynamic {
    public:
        PiNerdDynamic(int size) {
            m_pi = new int[size];  // alloc array
            m_size = size;  // store its size
            for (int j = 0; j < m_size; j++) {
                m_pi[j] = getPiDigit(j);
            }
        }
        ~PiNerdDynamic() {
            delete [] m_pi;  // free memory
        }
        void showOff() {
            for (int j = 0; j < m_size; j++) {
                std::cout << m_pi[j] << std::endl;
            }
        }
        int getPiDigit(int j) {
            return 1;
        }
    
    private:
        int* m_pi;
        int m_size;
};

int main() {
    int size = 3;  // can create a cin for this
    int* arr = new int[size];

    *arr = 10;
    *(arr+1) = 75;

    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    // we have 1 extra space at arr[2] if we wanted

    delete [] arr;

    PiNerd nerdy;
    nerdy.showOff();

    PiNerdDynamic superNerdy(2);
    superNerdy.showOff();
}