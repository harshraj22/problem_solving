``` c++
// help from editorial

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pi pair<int, int>

pi orient(pi cur) {
    if (cur.first > cur.second) 
        swap(cur.first, cur.second);

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d, k;
    cin >> n >> d >> k;

    // termination case:
    if (n <= d) {
        cout << "NO\n";
        return 0;
    }   else if (k == 1 && (d > 1 || n > 2)) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int> > graph(n+1);
    vector<int> degree(n+1, 0);
    set<pi> st;

    for (int i = 1; i <= d; i += 1) {
        int longest = max(i-1, d+1-i);
        st.insert({longest, i});

        graph[i].push_back(i+1);
        graph[i+1].push_back(i);

        degree[i] += 1;
        degree[i+1] += 1;
    }     

    st.insert({d, d+1});
    // Diameter is now created.

    for (int i = d+2; i <= n; i += 1) {
        if (st.empty()) {
            cout << "NO\n";
            return 0;
        }

        pi cur = *st.begin();
        st.erase(cur);

        if (degree[cur.second] == k) {
            i -= 1;
            continue;
        }   else if (cur.first == d) {
            i -= 1;
            continue;
        }

        // add edge
        graph[i].push_back(cur.second);
        graph[cur.second].push_back(i);

        // update degree
        degree[i] += 1;
        degree[cur.second] += 1;

        // if degree < k, insert again in set
        if (degree[i] < k) {
            st.insert(cur);
        }
        if (degree[i] < k) {
            st.insert({cur.first + 1, i});
        }
    }

    cout << "YES\n";

    set<pi> included;
    for (int i = 1; i <= n; i += 1) {
        for (auto d:graph[i]) {
            pi cur = {i, d};
            cur = orient(cur);
            if (included.find(cur) != included.end())
                continue;
            else {
                cout << i << " " << d << '\n';
                included.insert(cur);
            }
        }
    }

    return 0;
}

```