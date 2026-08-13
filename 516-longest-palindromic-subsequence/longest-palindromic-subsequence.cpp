class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),false));
        for(int i=s.length()-1;i>=0;i--){
            dp[i][i]=true;
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][s.length()-1];
    }
};