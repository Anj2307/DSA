class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int m=1;
        int l=0;
        unordered_set<char>so;
        for(int r=0;r<s.length();r++){
        
            if(!so.count(s[r])){
               so.insert(s[r]);
               m=max(m,r-l+1);
            }else{
                cout<<s[r];
                m=max(m,r-l);
                while(s[l]!=s[r]){
                    so.erase(s[l]);
                    l++;
                }
                so.erase(s[l]);
                l++;
                so.insert(s[r]);
            }
        }
        return m;
    }
};