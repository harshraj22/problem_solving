// https://practice.geeksforgeeks.org/problems/get-min-at-pop/1/

stack<int>_push(int arr[],int n) {
    stack<int> stk;
    stk.push(arr[0]);
    for (int i = 1; i < n; i += 1) 
        stk.push(min(stk.top(), arr[i]));
    return stk;
}

void _getMinAtPop(stack<int>s) {
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}