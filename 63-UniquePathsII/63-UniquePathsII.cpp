class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> memo(m, vector<int> (n, 0));
        if(v[0][0] == 1)
            memo[0][0] = 0;
        else 
            memo[0][0] = 1;
        for(int i = 0; i < m; i++){
            if(i == 0)
                continue;
            if(v[i][0] != 1 && memo[i-1][0] != 0)
                memo[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            if(i == 0)
                continue;
            if(v[0][i] != 1 && memo[0][i-1] != 0)
                memo[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(v[i][j] == 1)
                    memo[i][j] = 0;
                else 
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }

        return memo[m-1][n-1];

    }
};