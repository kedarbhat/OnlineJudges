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
  private:
    ListNode* reverse(ListNode* head) noexcept {
      ListNode* pre = nullptr;
      ListNode* cur = head;
      while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      return pre;
    }
 public:
  ListNode* reverseKGroup(ListNode* head, int k) noexcept {
    ListNode dummy = ListNode{0};
    dummy.next = head;
    auto* pre = &dummy;
    auto* end = &dummy;
    while (end->next != nullptr) {
      for (int i = 0; i < k && end != nullptr; i++) {
        end = end->next;
      }
      if (end == nullptr) {
        break;
      }
      ListNode* start = pre->next;
      ListNode* next = end->next;
      end->next = nullptr;
      pre->next = reverse(start);
      start->next = next;
      pre = start;
      end = pre;
    }
    return dummy.next;        
  }
};