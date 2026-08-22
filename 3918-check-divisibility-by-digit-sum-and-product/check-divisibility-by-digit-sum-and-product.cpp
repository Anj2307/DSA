class Solution {
public:
    bool checkDivisibility(int n) {
        string a= to_string(n);
        int b=0;
        int c=1;
        for(auto &i: a){
            b+=(int)(i-'0');
            c*=(int)(i-'0');
        }
        if(n%(b+c)==0) return true;
        return false;
    }
};