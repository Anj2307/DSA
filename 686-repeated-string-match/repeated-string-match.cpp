class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        int mi=(m+n-1)/n; 
        string s="";
        for (int i=0; i<mi; i++) {
            s += a;
        }
        if (s.find(b)!=-1) {
            return mi;
        }
        s+=a;
        if (s.find(b)!=-1) {
            return mi+1;
        }
        return -1;
    }
};
