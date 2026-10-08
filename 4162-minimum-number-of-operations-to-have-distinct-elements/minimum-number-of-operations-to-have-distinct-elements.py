from collections import defaultdict
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        m=defaultdict(int)
        for i in nums:
            m[i]+=1
        j=-3
        for i in range(len(nums)):
            if(m[nums[i]]>1):
                j=i
                m[nums[i]]-=1
        return int(j/3)+1