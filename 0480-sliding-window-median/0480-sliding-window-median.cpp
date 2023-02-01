class Solution {
    using ElementT = std::int64_t;
    using CountT = std::int32_t;
    using BalanceT = std::int32_t;
    template<template<typename...> class ComparatorT>
    using PriorityQueueT = std::priority_queue<ElementT, std::vector<ElementT>, ComparatorT<>>;
    using MaxHeapT = PriorityQueueT<std::less>;
    using MinHeapT = PriorityQueueT<std::greater>;

public:
    vector<double> medianSlidingWindow(const vector<int>& nums, const int k) {
        std::vector<double> medians;
        std::unordered_map<ElementT, CountT> removedElements;

        // prepare heaps with first k elements, then compute first window median
        MaxHeapT maxHeap(nums.cbegin(), std::next(nums.cbegin(), k));
        MinHeapT minHeap;
        while (minHeap.size() < k/2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        medians.push_back((k & 1) == 1 ? maxHeap.top() : (maxHeap.top() + minHeap.top()) * 0.5);

        for (auto i = k; i < nums.size(); ++i) {
            int incomingElement = nums[i];
            int outgoingElement = nums[i - k];
            ++removedElements[outgoingElement];
            
            // compute balance between heaps
            auto balance {outgoingElement <= maxHeap.top() ? -1 : 1};
            if (!maxHeap.empty() && incomingElement <= maxHeap.top()) {
                ++balance;
                maxHeap.push(incomingElement);
            } else {
                --balance;
                minHeap.push(incomingElement);
            }

            // balance out heaps
            if (balance < 0) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                ++balance;
            }
            if (balance > 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                balance--;
            }

            while (removedElements[maxHeap.top()] > 0) {
                --removedElements[maxHeap.top()];
                maxHeap.pop();
            }
            while (!minHeap.empty() && removedElements[minHeap.top()] > 0) {
                --removedElements[minHeap.top()];
                minHeap.pop();
            }
            medians.push_back((k & 1) == 1 ? maxHeap.top() : (maxHeap.top() + minHeap.top()) * 0.5);
        }
        return medians;   
    }
};