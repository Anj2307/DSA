class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s(banned.begin(),banned.end());
        int target=0;
        int count=0;
        for(int i=1;i<=n;i++){
           if(target+i>maxSum)
           {
            return count;
           }
           if(!s.count(i)){
           target+=i;
           count++;
           }
        }
        return count;
    
    }
};