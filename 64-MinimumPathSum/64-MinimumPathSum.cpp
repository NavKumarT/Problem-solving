class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return dp(grid, 0, 0, 0, m, n);
    }

    int dp(vector<vector<int>> grid, int i, int j, int sum, int rows, int cols){
        // if(i >= rows || j >= cols)
        //     return INT_MAX;
        // if(i == rows-1 && j == cols-1)
        //     return sum + grid[i][j];
        // return min(dp(grid, i, j+1, grid[i][j]+sum, rows, cols), dp(grid, i+1, j, grid[i][j]+sum, rows, cols));
        vector<vector<int>> memo(rows, vector<int> (cols, grid[0][0]));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 &&  j == 0)
                    continue;
                if(i-1 >= 0 && j-1 >= 0)
                    memo[i][j] = min(memo[i-1][j], memo[i][j-1]) + grid[i][j];
                else if(i-1 >= 0)
                    memo[i][j] = memo[i-1][j] + grid[i][j];
                else
                    memo[i][j] = memo[i][j-1] + grid[i][j];
            }
        }
        return memo[rows-1][cols-1];
    }
};