class Solution {
public:
    double myPow(double x, std::int64_t n, double acc=1.0) {
        if (n < 0) {
            return myPow(1/x, -n);
        }
        if (n == 0) {
            return acc;
        }
        if (n % 2 == 1) {
            return myPow(x*x, (n-1)/2, x*acc);
        }
        return myPow(x*x, n/2, acc);
    }
};