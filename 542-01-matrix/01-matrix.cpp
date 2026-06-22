class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> matrix(mat.size(), vector<int>(mat[0].size(), -1));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    matrix[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            auto r=p.first;
            int i=r.first;
            int j=r.second;
            int k=p.second;

            if(i>0 && matrix[i-1][j]==-1){
                matrix[i-1][j]=k+1;
                q.push({{i-1,j},k+1});
            }

            if(i<mat.size()-1 && matrix[i+1][j]==-1)
            {
                matrix[i+1][j]=k+1;
                q.push({{i+1,j},k+1});
            }

            if(j>0 && matrix[i][j-1]==-1){
                matrix[i][j-1]=k+1;
                q.push({{i,j-1},k+1});
            }

            if(j<mat[i].size()-1 && matrix[i][j+1]==-1){
                matrix[i][j+1]=k+1;
                q.push({{i,j+1},k+1});
            }
        }
        return matrix;
    }
};