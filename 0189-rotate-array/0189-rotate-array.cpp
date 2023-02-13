class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(std::next(nums.begin(), k), nums.end());
        std::reverse(nums.begin(), std::next(nums.begin(), k));
    }
};