class ZeroEvenOdd {
private:
    using FlagArrayT = std::bitset<3>;
    static constexpr auto ZERO_FLAG_IDX = std::size(FlagArrayT{})-1;
    FlagArrayT theFlags;
    std::atomic_int theCounter{0};
    bool terminateLoop{false};
    const int theN;

    static constexpr auto parityBit(int x) noexcept {
        return x & 1;
    }

public:
    ZeroEvenOdd(int n) : theN{n} 
    {
        theFlags[ZERO_FLAG_IDX] = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (theFlags[ZERO_FLAG_IDX]) {
                printNumber(0);
                auto myCounter = theCounter.fetch_add(1, std::memory_order_acq_rel);
                theFlags[ZERO_FLAG_IDX] = false;
                theFlags[parityBit(myCounter+1)] = true;
            } else {
                std::this_thread::yield();
            }
        } 
    }

    void even(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (const auto myCounter = theCounter.load(std::memory_order_acquire); parityBit(myCounter) == 0 && theFlags[parityBit(myCounter)]) {
                printNumber(myCounter);
                terminateLoop = myCounter >= theN;
                theFlags[parityBit(myCounter)] = false;
                theFlags[ZERO_FLAG_IDX] = true;
            } else {
                std::this_thread::yield();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (auto myCounter = theCounter.load(std::memory_order_acquire); parityBit(myCounter) == 1 && theFlags[parityBit(myCounter)]) {
                printNumber(myCounter);
                terminateLoop = theCounter >= theN;
                theFlags[parityBit(myCounter)] = false;
                theFlags[ZERO_FLAG_IDX] = true;
            } else {
                std::this_thread::yield();
            }
        }
    }
};