class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        a=k%len(nums)
        b=nums[len(nums)-a:]
        c=nums[:len(nums)-a]
        nums[:]=b+c


        
