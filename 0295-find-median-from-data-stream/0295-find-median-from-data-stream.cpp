class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::less<>>    smallerNumbersMaxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<>> largerNumbersMinHeap; 
public:    
    void addNum(int num) {
       if (smallerNumbersMaxHeap.empty() || num < smallerNumbersMaxHeap.top()) {
           smallerNumbersMaxHeap.push(num);
       } else {
           largerNumbersMinHeap.push(num);
       }

       while (smallerNumbersMaxHeap.size() > largerNumbersMinHeap.size()+1) {
           largerNumbersMinHeap.push(smallerNumbersMaxHeap.top());
           smallerNumbersMaxHeap.pop();
       }
       while (smallerNumbersMaxHeap.size() < largerNumbersMinHeap.size()) {
           smallerNumbersMaxHeap.push(largerNumbersMinHeap.top());
           largerNumbersMinHeap.pop();
       }
    }
    
    double findMedian() {
        if (((smallerNumbersMaxHeap.size() + largerNumbersMinHeap.size()) & 1) == 1) {
            return smallerNumbersMaxHeap.top();
        }
        return (smallerNumbersMaxHeap.top() + largerNumbersMinHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */