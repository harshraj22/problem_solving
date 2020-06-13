// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<int, Node*> refer;

    void create(Node* node, Node* head) {
        for (auto child: node->neighbors) {
            int val = child->val;
            if (refer.find(val) == refer.end()) {
                refer[val] = new Node(val);
                create(child, refer[val]);
            }
            head->neighbors.push_back(refer[val]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
       if (node == nullptr) return nullptr; 
       Node* head = new Node(node->val);
       refer[node->val] = head;
       create(node, head);
       return head; 
    }
};