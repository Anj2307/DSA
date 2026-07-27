class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<int>>vec(k,vector<int>(2));
        for(int i=0;i<vec.size();i++){
            vec[i][0]=INT_MIN;
            vec[i][1]=0;
        }
        
        for(auto price: prices){
            vec[0][0]=max(vec[0][0],-price);
            vec[0][1]=max(vec[0][1],vec[0][0]+price);
            for(int i=1;i<k;i++){
                vec[i][0]=max(vec[i][0],vec[i-1][1]-price);
                vec[i][1]=max(vec[i][1],vec[i][0]+price);
            }
        }
        return vec[k-1][1];
    }
};