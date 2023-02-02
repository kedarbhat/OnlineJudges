class BoundedBlockingQueue {
    std::queue<int> theQueue;
    const int theCapacity;
    std::mutex theQueueMtx;
    std::condition_variable theCv;
public:
    BoundedBlockingQueue(int capacity) : theCapacity(capacity) {
    }
    
    void enqueue(int element) {
        std::unique_lock myLock{theQueueMtx};
        theCv.wait(myLock, [&theQueue = theQueue, theCapacity = theCapacity]() { return theQueue.size() < theCapacity;});
        theQueue.emplace(element);
        theCv.notify_one();
    }
    
    int dequeue() {
        std::unique_lock myLock{theQueueMtx};
        theCv.wait(myLock, [&theQueue = theQueue, theCapacity = theCapacity]() { return !theQueue.empty(); });
        auto myFrontElement = theQueue.front();
        theQueue.pop();
        theCv.notify_one();
        return myFrontElement;
    }
    
    int size() {
        std::scoped_lock myLock{theQueueMtx};
        return static_cast<int>(theQueue.size());;
    }
};