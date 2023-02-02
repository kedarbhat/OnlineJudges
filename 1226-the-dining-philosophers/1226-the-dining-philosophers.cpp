class DiningPhilosophers {
   static constexpr auto NUM_PHILOSOPHERS{4};
   static constexpr auto NUM_FORKS{NUM_PHILOSOPHERS+1};
   std::bitset<5> theForkIsAvailable{31};
   std::mutex theForksMutex;
   std::condition_variable theCv;
   
   static constexpr auto getLeftForkIdx(int philosopher) noexcept {
       return philosopher % NUM_FORKS;
   }

   static constexpr auto getRightForkIdx(int philosopher) noexcept {
       return (philosopher+1) % NUM_FORKS;
   }

public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        const auto myLeftForkIdx = getLeftForkIdx(philosopher);
        const auto myRightForkIdx = getRightForkIdx(philosopher);
        {
            std::unique_lock myWaitingLock{theForksMutex};
            theCv.wait(myWaitingLock, [&]() { return theForkIsAvailable[myLeftForkIdx] && theForkIsAvailable[myRightForkIdx]; });
            theForkIsAvailable[myLeftForkIdx] = false;
            theForkIsAvailable[myRightForkIdx] = false;
            pickLeftFork();
            pickRightFork();
        }

        eat();

        std::lock_guard myDoneEatingLock{theForksMutex};
        putLeftFork();
        putRightFork();
        theForkIsAvailable[myLeftForkIdx] = true;
        theForkIsAvailable[myRightForkIdx] = true;
        theCv.notify_all();
    }
};