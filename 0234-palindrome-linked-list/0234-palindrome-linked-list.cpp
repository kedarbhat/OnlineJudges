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
public:
    bool isPalindrome(ListNode* head) noexcept {
        if (head == nullptr) {
            return true;
        }
        std::vector<int> theListNodeValues;
        auto* myPtr = head;
        while (myPtr != nullptr) {
            theListNodeValues.push_back(myPtr->val);
            myPtr = myPtr->next;
        }
        auto myFirst = theListNodeValues.cbegin();
        auto myLast = theListNodeValues.cend() - 1;
        while (myFirst < myLast) {
            if (*myFirst != *myLast) {
                return false;
            }
            ++myFirst;
            --myLast;
        }
        return true;
    }
};