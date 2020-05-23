// https://practice.geeksforgeeks.org/problems/merge-sort/1

void merge(int arr[], int l, int m, int r) {
    vector<int> ans(r-l+1);
    int first = l, second = m+1, index = 0;
    while (first <= m && second <= r) {
        if (arr[first] < arr[second]) {
            ans[index] = arr[first];
            first += 1; index += 1;
        }
        else {
            ans[index] = arr[second];
            second += 1; index += 1;
        }
    }

    while (first <= m) {
        ans[index] = arr[first];
        first += 1; index += 1;
    }

    while (second <= r) {
        ans[index] = arr[second];
        second += 1; index += 1;
    }

    for (int i = 0; i < ans.size(); i += 1) {
        arr[i+l] = ans[i];
    }
}