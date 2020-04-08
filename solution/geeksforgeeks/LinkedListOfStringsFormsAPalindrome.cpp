// https://practice.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

/*
The structure of linked list is the following
struct Node {
    string data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
bool compute(Node* root) {
    string input, rev;
    while(root != nullptr) {
        input += root->data;
        root = root->next;
    }
    
    rev = input;
    reverse(rev.begin(), rev.end());
    return rev == input;
}
