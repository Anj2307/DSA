class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        m={}
        for i in range(0,len(nums)):
            if(nums[i] in m):
                return [m[nums[i]],i]
            m[target-nums[i]]=i
        return []
            

        