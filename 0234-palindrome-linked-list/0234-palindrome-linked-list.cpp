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
    static constexpr ListNode* reverseList(ListNode* aNode) noexcept {
        ListNode* myPrev = nullptr;
        ListNode* myCurrent = aNode;
        ListNode* myNext = nullptr;
        while (myCurrent != nullptr) {
            myNext = myCurrent->next;
            myCurrent->next = myPrev;
            myPrev = myCurrent;
            myCurrent = myNext;
        }
        return myPrev;
    }
public:
    static constexpr bool isPalindrome(ListNode* head) noexcept {
        if (head == nullptr) {
            return true;
        }
        auto* myPtr = head;
        auto* myPtr2 = head;
        while (myPtr2 != nullptr && myPtr2->next != nullptr) {
            myPtr = myPtr->next;
            myPtr2 = myPtr2->next->next;
        }
        if (myPtr2 != nullptr) {
            myPtr = myPtr->next;
        }
        myPtr = reverseList(myPtr);
        myPtr2 = head;
        while (myPtr != nullptr) {
            if (myPtr->val != myPtr2->val) {
                return false;
            }
            myPtr = myPtr->next;
            myPtr2 = myPtr2->next;
        }
        return true;
    }
};