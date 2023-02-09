class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead{0};
        auto* curr = &dummyHead;
        auto carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            auto x = l1 != nullptr ? l1->val : 0;
            auto y = l2 != nullptr ? l2->val : 0;
            auto sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);

            // update ListNode pointers
            curr = curr->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        return dummyHead.next;
    }
};