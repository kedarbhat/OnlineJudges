class DiningPhilosophers {
   static constexpr auto NUM_PHILOSOPHERS{4};
   static constexpr auto NUM_FORKS{NUM_PHILOSOPHERS+1};
   std::array<std::mutex, NUM_FORKS> theForkMutexes;
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        auto philosopherEats = [=]() {
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
        };

        auto& myLeftFork = theForkMutexes[philosopher % theForkMutexes.size()];
        auto& myRightFork = theForkMutexes[(philosopher+1) % theForkMutexes.size()];
        if (philosopher % 2 == 1) {
            std::lock_guard myLeftLock{myLeftFork};
            std::lock_guard myRightLock{myRightFork};
            philosopherEats();
        } else {
            std::lock_guard myRightLock{myRightFork};
            std::lock_guard myLeftLock{myLeftFork};
            philosopherEats();
        }
    }
};