class Solution {
    static constexpr auto Calculate = [](int a, int b, int c) {
        return [=](int x) { return a*x*x + b*x + c; };
    };
public:
    vector<int> sortTransformedArray(const vector<int>& nums, int a, int b, int c) {
        auto myCalculator = Calculate(a, b, c);
        std::vector<int> result;
        result.reserve(nums.size());
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            auto leftResult = myCalculator(nums[left]);
            auto rightResult = myCalculator(nums[right]);
            if (a < 0) {
                if (leftResult < rightResult) {
                    result.emplace_back(leftResult);
                    ++left;
                } else {
                    result.emplace_back(rightResult);
                    --right;
                }
            } else {
                 if (leftResult > rightResult) {
                    result.emplace_back(leftResult);
                    ++left;
                } else {
                    result.emplace_back(rightResult);
                    --right;
                }
            }
        }
        if (a >= 0) {
            std::reverse(result.begin(), result.end());
        }
        return result;
    }
};