
class DiningPhilosophers {
private:
    std::mutex forks[5];

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        
        int leftForkId = philosopher;
        int rightForkId = (philosopher + 1) % 5;

        if (philosopher % 2 == 0) {
            forks[leftForkId].lock();
            forks[rightForkId].lock();
        } else {
            forks[rightForkId].lock();
            forks[leftForkId].lock();
        }

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forks[leftForkId].unlock();
        forks[rightForkId].unlock();
    }
};

