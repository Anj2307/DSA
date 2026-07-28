class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int>vec(26,0);
        for(int i=0;i<s.length();i++){
            vec[s[i]-'a']++;
        }
        string left="";
        string right="";
        string middle="";

        for(int i=0;i<26;i++){
            if(vec[i]==0) continue;
            else{
                int n=vec[i]/2;
                for(int j=0;j<n;j++){
                    left+=(char)i+'a';
                    right+=(char) i+'a';
                }
                if (vec[i]%2==1) middle+=(char)i+'a';
            }
        }
        reverse(right.begin(),right.end());
        return left+middle+right;

    }
};