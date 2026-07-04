class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
       
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, 1e9)); 
        dp[0][0] = 1; 
        dp[0][1] = 0;
        dp[0][2] = 1; 

        vector<vector<int>> vec(3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j) vec[i].push_back(j);
            }
        }

        for(int i = 0; i < obstacles.size() - 1; i++){
            for(int lane = 0; lane < 3; lane++) {
                if(obstacles[i + 1] != lane + 1) {
                    dp[i + 1][lane] = dp[i][lane];
                }
            }

           
            for(int lane = 0; lane < 3; lane++) {
                if(obstacles[i + 1] != lane + 1) {
                    
                    for(int side_lane : vec[lane]) {
                        if(obstacles[i + 1] != side_lane + 1) {
                            dp[i + 1][lane] = min(dp[i + 1][lane], dp[i + 1][side_lane] + 1);
                        }
                    }
                }
            }
        }

        int m = INT_MAX;
        for(int i : dp[obstacles.size() - 1]) {
            m = min(m, i);
        }
        return m;
    }
};
