// https://practice.geeksforgeeks.org/problems/heap-sort/1

/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
int leftChild(int node) {
    return node*2 + 1;
}

int rightChild(int node) {
    return node*2 + 2;
}

int parent(int node) {
    return node/2 - (node%2 == 0);
}

void heapify(int arr[], int n, int i)  {
    if (i >= n || leftChild(i) >= n) return;
    int lc = leftChild(i), rc = rightChild(i);
    if (arr[lc] > arr[i] && ((rc < n && arr[lc] > arr[rc]) || rc >= n)) {
        swap(arr[i], arr[lc]);
        heapify(arr, n, lc);
    }
    else if (arr[rc] > arr[i] && rc < n) {
        swap(arr[rc], arr[i]);
        heapify(arr, n , rc);
    }    
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    for (int i = n-1; i >= 0; i -= 1) 
        heapify(arr, n, i);
}
