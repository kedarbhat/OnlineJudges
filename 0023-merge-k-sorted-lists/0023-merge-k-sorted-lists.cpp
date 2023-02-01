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
    inline static constexpr auto compare = [](ListNode* lhs, ListNode* rhs) noexcept {
        return lhs->val > rhs->val;
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> heap(compare);
        for (auto* listNode : lists) {
            while (listNode != nullptr) {
                heap.push(listNode);
                listNode = listNode->next;
            }
        }
        if (heap.empty()) {
            return nullptr;
        }
        ListNode* result = heap.top();
        heap.pop();
        ListNode* dummy = result;
        while (!heap.empty()) {
            dummy->next = heap.top();
            heap.pop();
            dummy = dummy->next;
        }
        dummy->next = nullptr;
        return result;
    }
};