# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.totalSum = 0
        self.maxProd = 0
        
    def maxProduct(self, root: Optional[TreeNode]) -> int:    
            self.dfs(root)
            self.calculateSubTreeSum(root)
            return int(self.maxProd % (10**9 + 7))

    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.left)
        self.dfs(root.right)
        self.totalSum += root.val

    def calculateSubTreeSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        l = self.calculateSubTreeSum(root.left)
        r = self.calculateSubTreeSum(root.right)
        subTreeSum = l + r + root.val
        self.maxProd = max(self.maxProd, (subTreeSum) * (self.totalSum - subTreeSum))
        return subTreeSum
        