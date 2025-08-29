// Last updated: 8/29/2025, 9:49:47 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int> (cols, INT_MAX));
        for(int i = 0; i < cols; i++)
            memo[0][i] = matrix[0][i];
        
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                memo[i][j] = min(memo[i][j], memo[i-1][j]); // above 
                if(j-1 >= 0)
                memo[i][j] = min(memo[i][j], memo[i-1][j-1]); // top left
                if(j+1 < cols)
                memo[i][j] = min(memo[i][j], memo[i-1][j+1]); // top right
                memo[i][j] += matrix[i][j];
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i< cols; i++)
            ans = min(ans, memo[rows-1][i]);
        return ans;
    }
};