// https://practice.geeksforgeeks.org/problems/preorder-traversal/1

vector <int> preorder(Node* root) {
    Node* currentNode = root;
    stack<Node*> parents;
    vector <int> nodes;

    while (!parents.empty() || currentNode != nullptr) {
        while (currentNode == nullptr && !parents.empty()) {
            currentNode = parents.top();
            parents.pop();
        }

        if (currentNode != nullptr) {
            nodes.push_back(currentNode->data);
            if (currentNode->right != nullptr)
                parents.push(currentNode->right);
            currentNode = currentNode->left;
        }
    }

    return nodes;
}