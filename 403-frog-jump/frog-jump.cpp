class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size()==1) return true;
        if(stones.size()>1){
            if(stones[1]>1) return false;
        }
        
        vector<unordered_set<int>>dp(stones.size());
        unordered_map<int ,int>map;

        for(int i=0;i<stones.size();i++){
            map[stones[i]]=i;
        }

        dp[1].insert(1);

        for(int i=1;i<stones.size();i++){
            
            if(dp[i].size()==0) continue;
            else {
                for(auto j: dp[i]){
                    
                    if(j>1)
                    {
                        if(map.count(stones[i]+j-1))
                            dp[map[stones[i]+j-1]].insert(j-1);
                    }

                     if(map.count(stones[i]+j))
                        dp[map[stones[i]+j]].insert(j);
                    
                    if(map.count(stones[i]+j+1))
                        dp[map[stones[i]+j+1]].insert(j+1);

                }

            }
        }
        if(dp[stones.size()-1].size()==0)
            return false;
        

        return true;

        

    }
};