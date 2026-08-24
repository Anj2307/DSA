class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l=0;
        unordered_map<string, int>m;
        unordered_map<char,int>c;
        int ma=0;
        for(int r=0;r<s.size();r++){
            
                c[s[r]]++;
            if(r-l+1>minSize){
                c[s[l]]--;
                if(c[s[l]]==0)
                    c.erase(s[l]);
                l++;
            }
            if(r-l+1==minSize){
                if((int)c.size()<=maxLetters){
                    string sub=s.substr(l,minSize);
                    m[sub]++;
                    ma=max(m[sub],ma);
                }
            }

            
            
        }
        return ma;

    }
};