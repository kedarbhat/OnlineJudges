class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> myMinHeap;
        for (auto stick : sticks) {
            myMinHeap.push(stick);
        }
        int totalCost = 0;
        while (myMinHeap.size() > 1) {
            auto stick1 = myMinHeap.top();
            myMinHeap.pop();
            auto stick2 = myMinHeap.top();
            myMinHeap.pop();
            totalCost += stick1 + stick2;
            myMinHeap.push(stick1 + stick2);
        }
        return totalCost;
    }
};