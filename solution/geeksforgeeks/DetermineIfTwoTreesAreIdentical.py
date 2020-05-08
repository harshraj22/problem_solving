# https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

'''
class Node:
    def _init_(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
# your task is to complete this function
# function should return true/false or 1/0

def isIdentical(root1, root2):
    if root1 == None and root2 == None:
        return True
    elif root1 == None or root2 == None:
        return False
    elif root1.data != root2.data:
        return False
    return all([isIdentical(root1.left, root2.left), isIdentical(root1.right, root2.right)])

'''
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2) {
    if (r1 == nullptr && r2 == nullptr)
        return true;
    else if (r1 == nullptr || r2 == nullptr)
        return false;
    else if (r1->data != r2->data)
        return false;
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}
'''