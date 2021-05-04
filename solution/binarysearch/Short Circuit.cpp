// https://binarysearch.com/problems/Short-Circuit

void print(set<char> st) {
    for (auto it: st) {
        cout << it << ' ';
    }
    cout << '\n';
}

void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph) {
    if (vis[node])
        return;
    vis[node] = true;
    for (auto child: graph[node])
        dfs(child, vis, graph);
}

bool solve(vector<string>& words) {
    map<char, queue<string>> mp;
    for (auto word: words)
        mp[word.front()].push(word);

    string start = words.front();
    vector<set<char>> circles;

    while (mp.empty() == false) {
        // print(mp);
        start = mp.begin()->second.front();
        mp.begin()->second.pop();
        if (mp.begin()->second.empty())
            mp.erase(mp.begin());

        // new entry
        circles.push_back(set<char>());

        char cur_last = start.back();
        circles.back().insert(start.front());
        while (cur_last != start.front()) {
            circles.back().insert(cur_last);
            // string c = /
            if (mp.find(cur_last) == mp.end())
                return false;
            string c = mp[cur_last].front();
            mp[cur_last].pop();

            if (mp[cur_last].empty())
                mp.erase(cur_last);
            cur_last = c.back();
        }
    }

    int n = circles.size();
    auto graph = vector<vector<int>> (n);

    for (auto ch: "abcdefghijklmnopqrstuvwxyz") {
        int last = -1;
        for (int i = 0; i < circles.size(); i += 1) {
            if (circles[i].find(ch) != circles[i].end()) {
                if (last != -1) {
                    graph[last].push_back(i);
                    graph[i].push_back(last);
                }

                last = i;
            }
        }
    }

    cout << "size of graph: " << n << '\n';
    // ensure the graph is connected component
    vector<bool> vis(n, false);
    dfs(0, vis, graph);

    return all_of(vis.begin(), vis.end(), [](bool x) {return x == true;});
}