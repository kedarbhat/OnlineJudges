class ZeroEvenOdd {
private:
    std::atomic_flag thePrintZero = ATOMIC_FLAG_INIT;
    std::atomic_flag thePrintEven = ATOMIC_FLAG_INIT;
    std::atomic_flag thePrintOdd = ATOMIC_FLAG_INIT;
    int theCounter{0};
    const int theN;

static constexpr bool isOdd(int x) noexcept {
    return x & 1 == 1;
}

public:
    ZeroEvenOdd(int n) : theN{n} 
    {
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (theCounter <= theN) {
            if (!thePrintZero.test_and_set(std::memory_order_acquire)) {
                if (theCounter < theN) {
                    printNumber(0);
                }
                ++theCounter;
                if (isOdd(theCounter)) {
                    thePrintOdd.clear(std::memory_order_release);
                } else {
                    thePrintEven.clear(std::memory_order_release);
                }
            } else {
                std::this_thread::yield();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        while (theCounter <= theN) {
            if (!isOdd(theCounter) && !thePrintEven.test_and_set(std::memory_order_acquire)) {
                printNumber(theCounter);
                thePrintZero.clear(std::memory_order_release);
            } else {
                std::this_thread::yield();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (theCounter <= theN) {
            if (isOdd(theCounter) && !thePrintOdd.test_and_set(std::memory_order_acquire)) {
                printNumber(theCounter);
                thePrintZero.clear(std::memory_order_release);
            } else {
                std::this_thread::yield();
            }
        }
    }
};