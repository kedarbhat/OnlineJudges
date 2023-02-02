class ZeroEvenOdd {
private:
    std::condition_variable theCv;
    std::mutex theMutex;
    bool thePrintZero{true};
    int theCounter{1};
    const int theN;
public:
    ZeroEvenOdd(int n) : theN{n} 
    {
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> myLock{theMutex};
            theCv.wait(myLock, [&]() { return thePrintZero || theCounter > theN; });
            if (theCounter > theN) {
                break;
            }
            printNumber(0);  
            thePrintZero = false;
            theCv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> myLock{theMutex};
            theCv.wait(myLock,
                       [&]() { return (!thePrintZero && theCounter % 2 == 0) || theCounter > theN; });
            if (theCounter > theN) {
                break;
            }
            printNumber(theCounter);    
            ++theCounter;
            thePrintZero = true;
            theCv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> myLock{theMutex};
            theCv.wait(myLock,
                       [&]() { return (!thePrintZero && theCounter % 2 == 1) || theCounter > theN; });
            if (theCounter > theN) {
                break;
            }
            printNumber(theCounter);    
            ++theCounter;
            thePrintZero = true;
            theCv.notify_all();
        }
    }
};