class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int lhsIdx = 0;
      int rhsIdx = nums.size()-1;
      while (lhsIdx <= rhsIdx)
      {
        auto currentIdx = lhsIdx + (rhsIdx - lhsIdx) / 2;
        if (nums[currentIdx] == target)
        {
          return currentIdx;
        }
        if (target < nums[currentIdx])
        {
          rhsIdx -= 1; 
        }
        else
        {
          lhsIdx += 1;
        }
      }
      return lhsIdx;
    }
};