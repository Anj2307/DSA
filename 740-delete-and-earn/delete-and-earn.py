from collections import defaultdict
class Solution:
    def deleteAndEarn(self, nums: list[int]) -> int:
        m=max(nums)
        l=[0]*(m+1)
        for i in nums:
            l[i]+=i
        prev1=0
        prev2=0
        curr=0
        for i in l:
            curr=max(prev1, i+prev2)
            prev2=prev1
            prev1=curr
        return prev1

        
        