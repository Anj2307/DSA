from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        a=0
        m=defaultdict(int)
        m[0]+=1
        t=0
        for i in nums:
            a+=i
            if a-k in m:
                t+=m[a-k]
            m[a]+=1
        return t

            



        