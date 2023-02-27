class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums2) > len(nums1):
            return self.intersection(nums2, nums1)
        nums1_set = set(nums1)
        return list({i for i in nums2 if i in nums1})

