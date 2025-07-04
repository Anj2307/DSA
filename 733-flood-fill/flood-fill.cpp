class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int c) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] != c || image[sr][sc] == color) return;

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, color, c);
        dfs(image, sr - 1, sc, color, c);
        dfs(image, sr, sc + 1, color, c);
        dfs(image, sr, sc - 1, color, c);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor != color)
            dfs(image, sr, sc, color, originalColor);
        return image;
    }
};
