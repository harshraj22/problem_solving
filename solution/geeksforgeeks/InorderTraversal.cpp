// https://practice.geeksforgeeks.org/problems/inorder-traversal/1

// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root) {
    Node* currentNode = root;
    stack<Node*> parent;
    vector<int> nodes;

    // initialize stack somehow
    while (!parent.empty() || currentNode != nullptr) {
    	// left subtree visited, now visit right subtree
    	while (currentNode == nullptr && !parent.empty()) {
    		currentNode = parent.top();
    		parent.pop();
    		nodes.push_back(currentNode->data);
    		currentNode = currentNode->right;
    	}

        if (currentNode != nullptr) {
        	parent.push(currentNode);
        	currentNode = currentNode->left;
        }
    }

    return  nodes;
}
