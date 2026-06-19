class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int p){
        
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }
        if (image[sr][sc] == p) {
            image[sr][sc] = color;
            dfs(image, sr - 1, sc, color, p);
            dfs(image, sr, sc - 1, color, p);
            dfs(image, sr + 1, sc, color, p);
            dfs(image, sr, sc + 1, color, p);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
