class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int p = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == m - 1 && y == n - 1) return p;

        
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int effort = max(p, abs(heights[x][y] - heights[nx][ny]));
                    if (dist[nx][ny] > effort) {
                        dist[nx][ny] = effort;
                        pq.push({effort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};
