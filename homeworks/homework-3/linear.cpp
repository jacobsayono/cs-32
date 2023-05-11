// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n) {
    if (n < 0) return false;
    if (n == 0) return true;
    if (n == 1) return somePredicate(a[n-1]);
    
    bool first = allTrue(a, n/2);
    bool second = allTrue(a + n/2, n - n/2);
    
    return (first == true && second == true);
}

// Return the number of elements in the array for which the
// somePredicate function returns true.
int countTrue(const string a[], int n) {
    int counter = 0;
    if (n <= 0) return 0;
    if (n == 1) {
        if (somePredicate(a[n-1]) == true)
            counter++;
        return counter;
    }
    
    int first = countTrue(a, n/2);
    int second = countTrue(a + n/2, n - n/2);
    
    return first + second;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrue(const string a[], int n) {
    int pos = 0;
    if (n <= 0) return -1;
    if (n == 1) {
        if (somePredicate(a[n-1]) == true)
            return pos;
        pos++;
        return -1;
    }
    
    int first = firstTrue(a, n/2);
    int second = firstTrue(a + n/2, n - n/2);
    if (first == -1 && second == -1)
        return -1;
    if (first == -1 && second != -1)
        return n/2 + second;
    else
        return first;
    
}

// Return the subscript of the first string in the array that is >= all
// strings in the array (i.e., return the smallest subscript m such
// that a[m] >= a[k] for all k from 0 to n-1).  If the function is told
// that no strings are to be considered to be in the array, return -1.
int positionOfMax(const string a[], int n) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 0;
    }
    
    int maxPos = 1 + positionOfMax(a+1, n-1);

    if (a[0] >= a[maxPos]) {
        return 0;
    }

    return maxPos;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "john" "sonia" "elena" "ketanji" "sonia" "elena" "samuel"
// then the function should return true if a2 is
//    "sonia" "ketanji" "samuel"
// or
//    "sonia" "elena" "elena"
// and it should return false if a2 is
//    "sonia" "samuel" "ketanji"
// or
//    "john" "ketanji" "ketanji"
bool contains(const string a1[], int n1, const string a2[], int n2) {
    if (n2 <= 0)
        return true;
    if (n1 <= 0 || n1 < n2)
        return false;
    if (a1[n1-1] == a2[n2-1])
        return contains(a1, n1-1, a2, n2-1);
    else
        return contains(a1, n1-1, a2, n2);
}