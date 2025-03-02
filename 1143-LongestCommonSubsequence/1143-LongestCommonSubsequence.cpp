class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m+1, vector<int> (n+1, 0));
        return dp(m, n, text1, text2, memo);
    }

    int dp(int m, int n, string text1, string text2, vector<vector<int>> &memo){
        // if(i >= m || j >= n)
        //     return 0;
        // if(memo[i][j] != -1)
        //     return memo[i][j];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    memo[i][j] = 1 + memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[m][n];
        // else {
        //     int res;
        //     if(text1[i] == text2[j]){
        //     res =  1 + dp(i+1, j+1, m, n, text1, text2, memo);
        //     } else {
        //         res =  max(dp(i+1, j, m, n, text1, text2, memo), dp(i, j+1, m, n, text1, text2, memo));
        //     }
        //     memo[i][j] = res;
        //     return res;
        // }
    }
};