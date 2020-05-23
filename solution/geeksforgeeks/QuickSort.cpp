// https://practice.geeksforgeeks.org/problems/quick-sort/1

int partition (int arr[], int low, int high) {
    int left = low, right = high;    
    while (left < right) {
        while (left < high && arr[left] < arr[high])
            left += 1;
        while (right > low && arr[right] >= arr[high])
            right -= 1;
        if (left < right)
            swap(arr[left], arr[right]);
        else 
            break;
    }

    swap(arr[left], arr[high]);
    return left;
}