class Solution:
    def find_mul(self,n):
        b=1
        a=str(n)
        for i in a:
            b*=int(i)
        return b


    def smallestNumber(self, n: int, t: int) -> int:
        while(True):
            if(self.find_mul(n)%t==0):
                return n
            else: n+=1
        