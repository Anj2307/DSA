class Solution {
private:
    int f(vector<int>&vec,int n){
        if(n==0) return 0;
        if(vec[n]!=-1) return vec[n];
        for(int i=1;i*i<=n;i++){
           if(f(vec,n-i*i)==0){
            return vec[n]=1;
           }
        }
        return vec[n]=0;

    }
public:
    bool winnerSquareGame(int n) {
        vector<int>vec(n+1,-1);
        if(f(vec,n)==1)
        return true;
        return false;

    }
};