class Foo {
    std::atomic_flag printSecondFlag = ATOMIC_FLAG_INIT;
    std::atomic_flag printThirdFlag = ATOMIC_FLAG_INIT;

public:
    Foo() {
        printSecondFlag.test_and_set();
        printThirdFlag.test_and_set();
    }
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        printSecondFlag.clear();

    }

    void second(function<void()> printSecond) {
        // printSecond() outputs "second". Do not change or remove this line.
        while (printSecondFlag.test_and_set()) {}
        printSecond();
        printThirdFlag.clear();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        while (printThirdFlag.test_and_set()) {}
        printThird();
    }
};