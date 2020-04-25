// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

int *mergeKArrays(int arr[][N], int k) {
    vector<int> v(k, 0);
    int *ans = new int[k*k], next = 0, n = k;
    
    while (next != k*k) {
        pair<int, int> mn = {0, INT_MAX};
        // the following search can be transformed from O(k) to O(logk) 
        // using some sorted Data Structure like set/ priority_queue
        for (int i = 0; i < k; i += 1) {
            if (v[i] == n) continue;
            else if (arr[i][v[i]] < mn.second)
                mn = make_pair(i, arr[i][v[i]]);
        }
        
        ans[next] = mn.second;
        next += 1;
        v[mn.first] += 1;
    }
    
    return ans;
}