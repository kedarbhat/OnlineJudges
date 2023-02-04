class Foo {
   std::mutex theMutex;
   std::condition_variable theCv;
   std::atomic_int theCounter{1};

public:
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        theCounter.store(2, std::memory_order_release);
        theCv.notify_all();
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&theCounter = theCounter]() { return theCounter.load(std::memory_order_acquire) == 2; });
        }
        printSecond();
        theCounter.store(3, std::memory_order_release);
        theCv.notify_all();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&theCounter = theCounter]() { return theCounter.load(std::memory_order_acquire) == 3; });
        }
        printThird();
    }
};