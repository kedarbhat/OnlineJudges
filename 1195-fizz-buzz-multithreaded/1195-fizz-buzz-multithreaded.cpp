class FizzBuzz {
private:
    std::mutex theMutex;
    std::condition_variable theCv;
    const int theN;
    int theCounter;

public:
    FizzBuzz(int n) : theN{n}, theCounter{1} {
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(theCounter <= theN) {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&]() { return theCounter > theN || (theCounter % 3 == 0 && theCounter % 5 != 0); });
            if (theCounter <= theN) {
                printFizz();
                ++theCounter;
                theCv.notify_all();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(theCounter <= theN) {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&]() { return theCounter > theN || (theCounter % 3 != 0 && theCounter % 5 == 0); });
            if (theCounter <= theN) {
                printBuzz();
                ++theCounter;
                theCv.notify_all();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(theCounter <= theN) {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&]() { return theCounter > theN || theCounter % 15 == 0; });
            if (theCounter <= theN) {
                printFizzBuzz();
                ++theCounter;
                theCv.notify_all();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(theCounter <= theN) {
            std::unique_lock myLock{theMutex};
            theCv.wait(myLock, [&]() { return theCounter > theN || (theCounter % 3 != 0 && theCounter % 5 != 0); });
            if (theCounter <= theN) {
                printNumber(theCounter);
                ++theCounter;
                theCv.notify_all();
            }      
        }
    }
};