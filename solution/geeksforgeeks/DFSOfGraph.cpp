// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/* 

    [&](int i)->void {};
    ^
capture list(the values of outer function
that will be accessible by reference to 
the lambda function). If no vairable is 
specified (as in this case, all vaiables
are captured)


    [&](int i)->void {};
        ^
parameters to the labmda function


    [&](int i)->void {};
                ^
    return type of lambda function

To make a recursive lambda function, use
std::function

    function<void(int)>
              ^
return type of the function


    function<void(int)>
                    ^
parameters of the function

*/

void dfs(int s, vector<int> g[], bool vis[]) {
    // defing a variable
    function<void(int)> recur;

    // assign it lambda function
    recur = [&](int node) {
        cout << node << ' ';
        // captures all available variables by reference
        if (vis[node])
            return;
        vis[node] = true;
        for (auto it:g[node]) {
            if (vis[it] == false) {
                // notice the recursion
                recur(it);
            }
        }
    };
    
    recur(s);
}
