class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int count1 = 0;
        for(char c:s) if(c == '1') count1++;
        int count0 = s.size() - count1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == target[i]) continue;
            if(s[i] =='0'){
                if(!count1) return false;
                count1++;
            }
        }
        for(int i = 0;i<s.size();i++){
            if(s[i] == target[i]) continue;
            if(s[i] =='1'){
                if(count1-1<=0) return false;
                count1--;
            }
        }
        return true;
    }
};