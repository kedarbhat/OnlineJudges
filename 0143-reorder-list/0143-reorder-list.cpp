/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        ListNode* slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        auto* current = slow->next;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        slow->next = nullptr;

        // Step 3: Merge the two halves of the linked list
        auto* p1 = head;
        auto* p2 = prev;
        ListNode* tmp = nullptr;
        while (p2) {
            tmp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = tmp;
        }
    }
};
