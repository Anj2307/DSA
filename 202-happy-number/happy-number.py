class Solution:
    def isHappy(self, n: int) -> bool:
        seen =set()
        while(n!=1 and n not in seen):
            seen.add(n)
            a=str(n)
            c=0
            for i in a:
                c+=(ord(i)-ord('0'))**2
            n=c

        return n == 1
