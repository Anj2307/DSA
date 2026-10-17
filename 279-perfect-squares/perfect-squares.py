import math as m
from collections import deque
class Solution:
    def numSquares(self, n: int) -> int:
       sq=[i**2 for i in range(1, int(n**0.5)+1)]
       q=deque()
       q.append((n,0))
       vis={n}
       step=0
       while q:
        rem,step=q.popleft()
        for s in sq:
            if rem<s:
                break
            if rem==s:
                return step+1
            n_rem=rem-s
            if n_rem not in vis:
                vis.add(n_rem)
                q.append((n_rem,step+1))
       return step
