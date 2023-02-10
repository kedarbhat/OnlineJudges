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
    static constexpr auto compare(ListNode* lhs, ListNode* rhs) noexcept {
        return lhs->val < rhs->val;
    }

    ListNode* mergeTwoLists(ListNode* lhs, ListNode* rhs) const noexcept {
        if (lhs == nullptr && rhs == nullptr) {
            return nullptr;
        }
        if (lhs == nullptr || rhs == nullptr) {
            return lhs == nullptr ? rhs : lhs;
        }

        ListNode result{0};
        auto* dummy = &result;

        while (lhs != nullptr && rhs != nullptr) {
            dummy->next = compare(lhs, rhs) ? lhs : rhs;
            if (compare(lhs, rhs)) {
                lhs = lhs->next;
            } else {
                rhs = rhs->next;
            }
            dummy = dummy->next;
        }

        if (lhs != nullptr) {
            dummy->next = lhs;
        } else if (rhs != nullptr) {
            dummy->next = rhs;
        }
        return result.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        const auto numLists = lists.size();
        auto stepSize = 1;
        while (stepSize < numLists) {
            for (auto i{0}; i+stepSize < numLists; i += 2*stepSize) {
                lists[i] = mergeTwoLists(lists[i], lists[i + stepSize]);
            }
            stepSize *= 2;
        }
        return lists.front();
    }
};