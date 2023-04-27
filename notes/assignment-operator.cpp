#include <iostream>

class Circ {
    public:
        Circ(float x, float y, float r) {
            m_x = x;
            m_y = y;
            m_r = r;
        }

        // copy constructor
        // const promises we won't modify
        // the old variable while constructing new variable
        // make sure variable is a reference of the Circ type
        Circ(const Circ &old) {
            // copy old member variable values
            m_x = old.m_x;
            m_y = old.m_y;
            m_r = old.m_r;
        }

        // assignment operator
        // return type must be a reference to the class type
        Circ &operator=(const Circ &old) {
            m_x = old.m_x;
            m_y = old.m_y;
            m_r = old.m_r;
            return *this;  // Cric &
        }

    private:
        float m_x, m_y, m_r;
};



// constructor and assignment operator for dynamic allocation prevents
// deleting the same memory both points to
// which default copy constructors would do
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
            // when we destruct a copy, the original won't get destructed yet, so we are good
        }

        // copy constructor: very similar to original constructor
        PiNerdDynamic(const PiNerdDynamic &src) {
            m_size = src.m_size;  // copy number of slots in array
            m_pi = new int [m_size];  // allocate its own copy of int dynamic memory, so m_pi gets its own array
            for (int j = 0; j < m_size; j++) {  // loop manually copies over contents of original array
                m_pi[j] = src.m_pi[j];  // m_pi has its own copy of all the data in the original array stored in its own memory location
            }
        }

        // assignment operator: very similar to copy constructor
        // return type is a reference to the class type
        PiNerdDynamic &operator=(const PiNerdDynamic &src) {
            // check to see if a variable is being assigned to itself
            // anti-alias protection
            if (&src == this) {
                return *this;
            }
            delete [] m_pi;  // first, free any memory currently held by the target variable (ben)
            m_size = src.m_size;  // copy number of slots in array
            m_pi = new int [m_size];  // allocate its own copy of int dynamic memory, so m_pi gets its own array
            for (int j = 0; j < m_size; j++) {  // loop manually copies over contents of original array
                m_pi[j] = src.m_pi[j];  // m_pi has its own copy of all the data in the original array stored in its own memory location
            }
            return *this;  // returns the target object
            // return *this allows us to do multiple assignments
            // like: cam = ben = ann;
            // all will be equal to ann
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
        // class has pointer member variable
        // so there's a good chance we need
        // assignment operator and copy constructor
        int* m_pi;
        int m_size;
};

int main() {
    Circ a(1, 2, 3);
    Circ b(a);
    Circ c = a;

    PiNerdDynamic ann(3);
    PiNerdDynamic ben(4);
    // assignment operator (works similar to copy but resolves issue if ann and ben have different memory sizes)
    ben = ann;
}