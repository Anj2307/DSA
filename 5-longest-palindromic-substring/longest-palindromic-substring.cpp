class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));
        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
        }
        if(s.length()==1) return s;
        int ma=1;
        string m="";
        m+=s[0];
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    if(j-i<=2||dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        if(ma<(j-i+1)){
                            ma=j-i+1;
                            m=s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return m;
    }
};