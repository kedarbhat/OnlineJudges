class MedianFinder {
    std::priority_queue<int> maxQueue;
    std::priority_queue<int, std::vector<int>, std::greater<>> minQueue;
public:    
    void addNum(int num) {
       if (maxQueue.empty() || num < maxQueue.top()) {
           maxQueue.push(num);
       } else {
           minQueue.push(num);
       }

       while (maxQueue.size() > minQueue.size()+1) {
           minQueue.push(maxQueue.top());
           maxQueue.pop();
       }
       while (maxQueue.size() < minQueue.size()) {
           maxQueue.push(minQueue.top());
           minQueue.pop();
       }
    }
    
    double findMedian() {
        if (((maxQueue.size() + minQueue.size()) & 1) == 1) {
            return maxQueue.top();
        }
        return (maxQueue.top() + minQueue.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */