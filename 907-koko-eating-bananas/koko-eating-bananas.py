
import math
class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        a=1
        b=max(piles)
        mid=0
        while(a<b):
            mid=(a+b)//2
            c=0
            for i in piles:
                c+=math.ceil(i/mid)
            if(c>h):
                a=mid+1
            else:
                b=mid
        return a