// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// Idea is to store 2 numbers at one index (upper bound of input numbers is given)

vector<int> duplicates(int a[], int n) {
    int mod = n;    vector<int> dup;
    for (int i = 0; i < n; i += 1) {
        int num = a[i] % mod;
        int freq = a[num]/mod;
        a[num] = a[num] % mod + (freq+1) * mod;
    }

    for (int i = 0; i < n; i += 1) {
        int freq = a[i] / mod;
        if (freq > 1)
            dup.push_back(i);
    }

    return (dup.empty() ? vector<int> (1, -1): dup);
}


