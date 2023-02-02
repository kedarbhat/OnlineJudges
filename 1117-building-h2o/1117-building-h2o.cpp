class H2O {
    std::mutex theMutex;
    std::condition_variable theCv;
    int theOxygenCount;
    int theHydrogenCount;

private:
    void resetCounters() {
         if (theHydrogenCount == 2 && theOxygenCount == 1) {
            theHydrogenCount = 0;
            theOxygenCount = 0;
        }
    }
public:
    H2O() : theOxygenCount{0}, theHydrogenCount{0} {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock myLock{theMutex};
        theCv.wait(myLock, [&theHydrogenCount=theHydrogenCount]() { return theHydrogenCount < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++theHydrogenCount;
        resetCounters();
        theCv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock myLock{theMutex};
        theCv.wait(myLock, [&theOxygenCount=theOxygenCount]() { return theOxygenCount < 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++theOxygenCount;
        resetCounters();
        theCv.notify_one();
    }
};