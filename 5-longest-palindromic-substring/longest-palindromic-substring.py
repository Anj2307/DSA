class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)==0: return ""
        dp=[[False for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i]=True
        mx=1
        p=str(s[0])

        for i in range(len(s)-1,-1,-1):
            for j in range(i+1,len(s)):
                if(s[i]==s[j]):
                    if(j-i<=2 or dp[i+1][j-1]):
                        dp[i][j]=True
                        if(mx<(j-i+1)):
                            mx=j-i+1
                            p=s[i:j+1]
        return p

