class Solution {
public:
    int minDistance(string text1, string text2) {
         vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),0));
            char t1=text1[0];
            bool flag=false;
            for(int i=0;i<text2.length();i++){
                if(text2[i]==t1)
                    flag=true;
                if(flag)
                    dp[0][i]=1;
                else dp[0][i]=0;
            }
            flag=false;
            for(int i=0;i<text1.length();i++){
                if(text1[i]==text2[0]){
                    flag=true;
                }
                if(flag) dp[i][0]=1;
                else dp[i][0]=0;
            }

            for(int i=1;i<text1.length();i++){
                for(int j=1;j<text2.length();j++){
                    if(text1[i]==text2[j]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
            return text1.length()+text2.length()-2*dp[text1.length()-1][text2.length()-1];

    }
};