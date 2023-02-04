class Solution {
    std::random_device rd;
    int partition(vector<int>& nums, int left, int right) {
        std::mt19937 eng{rd()};
        std::uniform_int_distribution dist(left, right);
        auto pivotIdx = dist(eng);
        auto pivot = nums[pivotIdx];
        std::swap(nums[pivotIdx], nums[right]);
        auto writeIdx = left;
        for (auto readIdx = left; readIdx < right; ++readIdx) {
            if (nums[readIdx] <= pivot) {
                std::swap(nums[readIdx], nums[writeIdx]);
                ++writeIdx;
            }
        }
        std::swap(nums[writeIdx], nums[right]);
        return writeIdx;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            auto pivotIdx = partition(nums, left, right);
            if (pivotIdx == k) {
                break;
            } else if (pivotIdx < k) {
                left = pivotIdx+1;
            } else {
                right = pivotIdx-1;
            }
        }
        return nums[k];
    }
};