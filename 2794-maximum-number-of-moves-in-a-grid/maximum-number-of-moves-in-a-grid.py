class Solution:
    def f(self,dp,grid,i,j):
        if i>=len(grid) or j>=len(grid[0]) or i<0 or j<0:
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        ma=0
        dir=[(-1,1),(0,1),(1,1)]
        for ni,nj in [(i+di,j+dj)for di,dj in dir]:
            if 0<=ni<len(grid) and 0<=nj<len(grid[0]) and grid[ni][nj]>grid[i][j]:

                ma=max(ma,1+self.f(dp,grid,ni,nj))
        dp[i][j]=ma
        return dp[i][j]

        
    def maxMoves(self, grid: List[List[int]]) -> int:
        dp=[[-1 for i in range(len(grid[0]))] for j in range(len(grid))]
        ma=0
        for r in range(len(grid)):
            ma=max(ma,self.f(dp,grid,r,0))
        return ma