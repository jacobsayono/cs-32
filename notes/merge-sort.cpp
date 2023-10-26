// O(nlog(n)) for all
// stable
// takes more memory

void merge(int data[], int n1, int n2, int temp[]) {
    int i1 = 0, i2 = 0, k = 0;
    // pass in input array called data and the sizes of the 2 parts of it to merge: n1 and n2
    int *A1 = data, *A2 = data + n1;

    // temp is temporary array of size n1+n2 that holds the merged results as we loop
    while (i1 < n1 || i2 < n2) {
        if (i1 == n1)
            temp[k++] = A2[i2++];
        else if (i2 == n2)
            temp[k++] = A1[i1++];
        else if (data[i1] <= A2[i2])
            temp[k++] = A1[i1++];
        else
            temp[k++] = A2[i2++];
    }
    // copy our merged results back to the data array 1 by 1
    for (int i = 0; i < n1 + n2; i++)
        data[i] = temp[i];
}

void mergesort(int data[], int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int* left = data;
    int* right = data + mid;

    mergesort(left, mid);
    mergesort(right, size - mid);

    int* temp = new int[size];
    merge(data, mid, size - mid, temp);
    delete[] temp;
}