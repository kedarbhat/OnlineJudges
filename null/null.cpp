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
    std::unordered_map<Node*, Node*> clonedNodes;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        if (Node* neighbor = clonedNodes[node]; neighbor != nullptr) {
            return neighbor;
        }

        Node* newNode = new Node(node->val);
        clonedNodes[node] = newNode;
        std::transform(node->neighbors.cbegin(), node->neighbors.cend(), 
            std::back_inserter(newNode->neighbors), 
            [&](Node* neighbor) { return cloneGraph(neighbor); });
        return newNode;
    }
};