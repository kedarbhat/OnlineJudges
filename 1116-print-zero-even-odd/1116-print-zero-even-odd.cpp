class ZeroEvenOdd {
private:
    using FlagArrayT = std::bitset<3>;
    static constexpr auto ZERO_FLAG_IDX = std::size(FlagArrayT{})-1;
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
        theFlags[ZERO_FLAG_IDX] = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (theFlags[ZERO_FLAG_IDX]) {
                printNumber(0);
                ++theCounter;
                theFlags[ZERO_FLAG_IDX] = false;
                theFlags[parityBit(theCounter)] = true;
            } else {
                std::this_thread::yield();
            }
        } 
    }

    void even(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (auto myParityBit = parityBit(theCounter); myParityBit == 0 && theFlags[myParityBit]) {
                printNumber(theCounter);
                terminateLoop = theCounter >= theN;
                theFlags[myParityBit] = false;
                theFlags[ZERO_FLAG_IDX] = true;
            } else {
                std::this_thread::yield();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (!terminateLoop) {
            if (auto myParityBit = parityBit(theCounter); myParityBit == 1 && theFlags[myParityBit]) {
                printNumber(theCounter);
                terminateLoop = theCounter >= theN;
                theFlags[parityBit(theCounter)] = false;
                theFlags[ZERO_FLAG_IDX] = true;
            } else {
                std::this_thread::yield();
            }
        }
    }
};