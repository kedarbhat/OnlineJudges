class FooBar {
private:
   std::atomic_flag theFooFlag = ATOMIC_FLAG_INIT;
   std::atomic_flag theBarFlag = ATOMIC_FLAG_INIT;
   const int theN;
public:
    FooBar(int n) : theN{n} {
        theFooFlag.clear();
        theBarFlag.test_and_set();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < theN; ++i) {            
        	// printFoo() outputs "foo". Do not change or remove this line.
            while (theFooFlag.test_and_set(std::memory_order_relaxed)) {
                std::this_thread::yield();
            }
        	printFoo();
            theBarFlag.clear();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < theN; ++i) {
        	// printBar() outputs "bar". Do not change or remove this line.
            while (theBarFlag.test_and_set(std::memory_order_relaxed)) {
                std::this_thread::yield();
            }
        	printBar();
            theFooFlag.clear();
        }
    }
};