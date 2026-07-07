class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        

        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++)
            {
                if(j==0){

                    matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if(j==matrix.size()-1){
                    matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j-1]);
                }
                else matrix[i][j]+=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1]));
            }

        }

        int m=INT_MAX;
        
            for(auto i: matrix[matrix.size()-1]){
                m=min(m,i);
            }
            return m;
        


    }
};