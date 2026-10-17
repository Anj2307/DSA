# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def build(self, left, right,nums):
        if left>right:
            return None
        mid=(left+right)//2
        node=TreeNode(nums[mid])
        node.left=self.build(left,mid-1,nums)
        node.right=self.build(mid+1,right,nums)
        return node
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode | None:
        return self.build(0,len(nums)-1,nums)