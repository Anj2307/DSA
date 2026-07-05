class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<bool> vec(n, false);
        vec[0] = true; 

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            int idx = u.first;
            int steps = u.second;

            if (idx == n - 1) return steps;

            
            if (idx + 1 < n && !vec[idx + 1]) {
                vec[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            
            if (idx - 0 > 0 && !vec[idx - 1]) {
                vec[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            
            if (map.find(arr[idx]) != map.end()) {
                for (auto it : map[arr[idx]]) {
                    if (!vec[it]) {
                        vec[it] = true;
                        q.push({it, steps + 1});
                    }
                }
                
                map.erase(arr[idx]);
            }
        }

        return 0;
    }
};
