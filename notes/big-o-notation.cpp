int main() {

    int n;
    int q;
    int sum;



    for (int i = 0; i < n; i += 2) {
        sum++;
    }
    // 1/2 * n ---> n
    // O(n)



    for (int i = 0; i < q; i++) {
        for (int j = 0; j < q; j++) {
            sum++;
        }
    }
    // O(n^2)



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*n; j++) {
            sum++;
        }
    }
    // O(n^3)



    int k = n;
    while (k > 1) {
        sum++;
        k = k/2;
    }
    // O(log(n))


    int k = 1;
    int n;
    while (k < n) {
        sum++;
        k = k * 2;
    }
    // O(log(n))


    for (int i = 0; i < n; i++) {
        int k = n;
        while (k > 1) {
            sum ++;
            k = k/3;
        }
    }
    // O(n*log(n))


    int p;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < i*i; j++) {
            for (int k = 0; k < j; k++) {
                // do smth
            }
        }
    }
    // O(n^5)


    struct Circ {
        Circ();
        void setRadius(int i);
    };

    for (int i = 0; i < n; i++) {
        Circ arr[n];
        arr[i].setRadius(i);
    }
    // array: circ circ circ circ ... n times
    // for loop n times
    // O(n^2)



    for (int i = 0; i < n; i++) {
        int k = n;
        while (k > 1) {
            sum++;
            k = k/2;
        }
    }
    // O(n*log(n))




}



void foo() {
    int n;
    int i, sum = 0;

    for (i = 0; i < n*n; i++) {
        sum += i;
    }
    
    for (i = 0; i < n*n*n; i++) {
        sum =+ i;
    }
}
// n^2 + n^3
// O(n^3)



int searchArray(int arr[], int n, int forValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == forValue) {
            return i;
        }
    }
    return -1;  // not found
}
// O(n)



void addItemToEndOfArray(int arr[], int &n, int addMe) {
    arr[n] = addMe;
    n = n + 1;
}
// O(1)



void mystery(int n) {
    for (int q = 0; q < n; q++) {
        for (int x = 0; x < q; x++) {
            // something
        }
    }
}
// n*(n-1)/2
// O(n^2)



void tinder(char csmajors[], int c, char eemajors[], int e) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            // smth
        }
    }
    for(int m = 0; m < c; m++) {
        // smth
    }

    for (int k = 0; k < e; k++) {
        // smth
    }
}
// c and e are independent variables
// c^2 + c + e
// O(c^2 + e)



void bar(int n, int q) {
    for (int i = 0; i < n*n; i++) {
        for(int j = 0; j < q; j++) {
            // smth
        }
    }
}
// O(n^2 * q)



void bard(int n, int q) {
    for (int i = 0; i < n; i++) {
        if (i == n/2) {
            for (int k = 0; k < q; k++) {
                // smth
            }
        }
    }
}
// q's for loop only runs at once instance when i == n/2
// O(n + q)