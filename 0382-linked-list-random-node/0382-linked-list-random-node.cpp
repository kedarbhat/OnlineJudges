/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    std::vector<int> theListNodeValues;
public:
    Solution(ListNode* head) {
        auto* myPtr = head;
        while (myPtr != nullptr) {
            theListNodeValues.push_back(myPtr->val);
            myPtr = myPtr->next;
        }
    }
    
    int getRandom() {
        return theListNodeValues[std::rand() % theListNodeValues.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */