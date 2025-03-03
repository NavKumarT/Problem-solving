class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        string rev = "";
        for(int i = m-1; i>= 0; i--)
            rev += s[i];
        return dp(m, m, s, rev);
    }

    int dp(int m, int n, string s, string r){
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == r[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else 
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[m][n];
    }
};