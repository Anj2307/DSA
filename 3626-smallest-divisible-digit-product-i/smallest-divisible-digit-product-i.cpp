class Solution {
private:
    bool check(int i, int t){
        string s=to_string(i);
        int num=1;
        for(auto j: s){
            num*=(j-'0');
        }
        if(num%t==0) return true;
        return false;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
           if(check(n,t))
            return n;
            n++;
        }
        return 0;
    }
};