class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));
        int p=0;

        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
            p++;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    if(j-i<=2||dp[i+1][j-1])
                        {
                            dp[i][j]=true;
                            p++;
                        }
                }
            }
        }
        return p;

    }
};