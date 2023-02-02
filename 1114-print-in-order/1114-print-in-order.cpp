class Foo {
   std::mutex theMutex;
   std::condition_variable theCv;
   int theCounter{1};

public:
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        theCounter = 2;
        theCv.notify_all();
    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock myLock{theMutex};
        theCv.wait(myLock, [&theCounter = theCounter]() { return theCounter == 2; });
        printSecond();
        theCounter = 3;
        theCv.notify_all();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock myLock{theMutex};
        theCv.wait(myLock, [&theCounter = theCounter]() { return theCounter == 3; });
        printThird();
        theCounter = 1;
    }
};