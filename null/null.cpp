/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> visitedNodes;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (visitedNodes[head] != nullptr) {
            return visitedNodes[head];
        }
        auto* newNode = new Node(head->val);
        visitedNodes[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};