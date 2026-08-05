class Solution {
private:
    long long calc(string &s, char a, char b){
        long long first=0, ans=0;
        for(char c: s){
            if(c==b) ans+=first;
            if(c==a) first++;

        }
        return ans;
        
    }
public:
    long long numOfSubsequences(string s) {
        long long l=0;
        long long t= count(s.begin(),s.end(),'T');
        long long base=0;
        long long bestlt=0;
        for(char c: s){
            if(c=='T') t--;
            if(c=='C')
                base+=l*t;
            if(c=='L')
                l++;
            bestlt=max(bestlt,l*t);
        }
        long long addl=calc(s,'C','T');
        long long addt= calc(s,'L','C');

        return base+max({bestlt,addl,addt});
    }
};