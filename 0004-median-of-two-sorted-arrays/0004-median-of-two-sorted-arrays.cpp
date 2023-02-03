class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        const int numElements = nums1.size()+nums2.size();
        int left = 0;
        int right = nums1.size();
        double result{0.0};
        while (left <= right) {
            const int aIdx = left+(right-left)/2;
            const int bIdx = (numElements + 1) / 2 - aIdx;
            const int aLeft = aIdx > 0 ? nums1[aIdx - 1] : INT_MIN;
            const int aRight = aIdx < nums1.size() ? nums1[aIdx] : INT_MAX;
            const int bLeft = bIdx > 0 ? nums2[bIdx - 1] : INT_MIN;
            const int bRight = bIdx < nums2.size() ? nums2[bIdx] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight) {
                if (numElements % 2 == 1) {
                    result = std::max(aLeft, bLeft);
                } else {
                    result = (std::max(aLeft, bLeft)+std::min(aRight, bRight))/2.0;
                }
                break;
            }

            if (aLeft > bRight) {
                right = aIdx-1;
            } else {
                left = aIdx+1;
            }
        }
        return result;
    }
};