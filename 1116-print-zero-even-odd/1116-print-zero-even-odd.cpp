class ZeroEvenOdd {
private:
using FlagArrayT = std::array<std::atomic_flag, 3>;
    static constexpr auto ZERO_FLAG_IDX = std::tuple_size_v<FlagArrayT>-1;
    FlagArrayT theFlags;
    bool terminateLoop{false};
    int theCounter{0};
    const int theN;

    static constexpr auto parityBit(int x) noexcept {
        return x & 1;
    }

public:
    ZeroEvenOdd(int n) : theN{n} 
    {
        for (auto&& myAtomicFlag : theFlags) {
            myAtomicFlag.test_and_set();
        }
        theFlags[ZERO_FLAG_IDX].clear();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (!theFlags[ZERO_FLAG_IDX].test_and_set(std::memory_order_acquire)) {
                printNumber(0);
                ++theCounter;
                theFlags[parityBit(theCounter)].clear(std::memory_order_release);
            } else {
                std::this_thread::yield();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (parityBit(theCounter) == 0 && !theFlags[parityBit(theCounter)].test_and_set(std::memory_order_acquire)) {
                printNumber(theCounter);
                terminateLoop = theCounter >= theN;
                theFlags[ZERO_FLAG_IDX].clear(std::memory_order_release);
            } else {
                std::this_thread::yield();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (parityBit(theCounter) == 1 && !theFlags[parityBit(theCounter)].test_and_set(std::memory_order_acquire)) {
                printNumber(theCounter);
                terminateLoop = theCounter >= theN;
                theFlags[ZERO_FLAG_IDX].clear(std::memory_order_release);
            } else {
                std::this_thread::yield();
            }
        }
    }
};