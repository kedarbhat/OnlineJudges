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
    static constexpr auto findListLength(ListNode*& tail) noexcept {
        auto length = 1;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
            ++length;
        }
        return length;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        auto* tail = head;
        const auto listLength = findListLength(tail);
        k %= listLength;
        auto* result = head;
        if (k == 0) {
            return result;
        }
        for (auto i = 0; i+k < listLength; ++i) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = nullptr;
            result = head;
        }
        return result;
    }
};