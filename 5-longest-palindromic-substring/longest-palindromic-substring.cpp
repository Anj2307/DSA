class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        vector<vector<bool>>vec(s.length(),vector<bool>(s.length(),false));
        for(int i=0;i<s.length();i++){
            vec[i][i]=true;
        }
        int m=0;
        string str="";
        str+=s[0];
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    if(j-i<=2 || vec[i+1][j-1]){
                        vec[i][j]=true;
                        if(m<j-i+1){
                            str=s.substr(i,j-i+1);
                        }
                        m=max(m,j-i+1);
                    }
                }
            }
        }
        return str;
    }
};