class FooBar {
private:
    std::mutex theMutex;
    std::condition_variable theCv;
    const int theN;
    bool theFooPrintable;

public:
    FooBar(int n) : theN{n}, theFooPrintable{true} {
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < theN; i++) {            
        	// printFoo() outputs "foo". Do not change or remove this line.
            std::unique_lock myLock {theMutex};
            theCv.wait(myLock, [&canProceed = theFooPrintable]() { return canProceed; });
        	printFoo();
            theFooPrintable = false;
            theCv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < theN; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            std::unique_lock myLock {theMutex};
            theCv.wait(myLock, [&cannotProceed = theFooPrintable]() { return !cannotProceed; });
        	printBar();
            theFooPrintable = true;
            theCv.notify_one();
        }
    }
};