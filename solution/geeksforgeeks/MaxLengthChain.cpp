// https://practice.geeksforgeeks.org/problems/max-length-chain/1
// See how sorting before dp is required !

int maxChainLen(struct val p[],int n) {
    vector<int> v(n, 1);
    auto cmp = [](struct val a, struct val b)->bool{
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    };

    sort(p, p+n, cmp);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < i; j += 1) {
            if (p[i].first > p[j].second)
                v[i] = max(v[i], 1 + v[j]);
        }
    } 

    return *max_element(v.begin(), v.end());
}