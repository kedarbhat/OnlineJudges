class Solution {
public:
    vector<int> sortTransformedArray(const vector<int>& nums, int a, int b, int c) {
        static constexpr auto Calculate = [](int a, int b, int c) {
            return [=](int x) { return a*x*x + b*x + c; };
        };
        std::vector<int> result;
        std::transform(nums.cbegin(), nums.cend(), std::back_inserter(result), Calculate(a, b, c));
        std::sort(result.begin(), result.end());
        return result;
    }
};