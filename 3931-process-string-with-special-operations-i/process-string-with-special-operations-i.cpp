class Solution {
public:
    string processStr(string s) {
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(result=="") continue;
                else {
                    result.erase(result.length()-1,1);
                }
            }
            else if(s[i]=='#'){
                if(result=="") continue;
                result+=result;
            }
            else if(s[i]=='%'){
                if(result=="") continue;
                reverse(result.begin(),result.end());
            }
            else result+=s[i];

        }
        return result;
    }
};