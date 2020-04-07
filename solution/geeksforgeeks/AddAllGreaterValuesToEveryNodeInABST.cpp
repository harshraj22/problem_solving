// https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1

// possibly this solution is an overkill
// see optimized: http://disq.us/p/28ao77k

vector<long long int> order, pref;
void getOrder(Node* root) {
    if (root == nullptr)
        return ;
        
    order.push_back(root->data);
    getOrder(root->left);
    getOrder(root->right);
}

void update(Node* root) {
    if (root == nullptr)
        return;
        
    auto index = lower_bound(order.begin(), order.end(), root->data) - order.begin();
    long long int sum = pref[index];
    
    root->data = sum;
    update(root->left);
    update(root->right);
}


void modify(Node **root) {
    order.clear();
    order.resize(0);
    
    getOrder(*root);
    sort(order.begin(), order.end());
    
    int n = order.size();
    pref.resize(n, 0);
    pref.back() = order.back();
    for (int i = n-2; i >= 0; i -= 1) 
        pref[i] = pref[i+1] + order[i];
    
    
    update(*root);
}