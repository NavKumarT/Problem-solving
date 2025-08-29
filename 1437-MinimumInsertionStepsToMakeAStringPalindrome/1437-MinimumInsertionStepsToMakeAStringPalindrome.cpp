// Last updated: 8/29/2025, 9:49:16 PM
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = "";
        for(int i = n-1; i>= 0; i--){
            t += s[i];
        }
        int lcs = dp(0, 0, s, t, n);
        return n-lcs;
    }

    int dp(int i, int j, string s, string t, int n){
        vector<vector<int>> memo(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <=n ;i++){
            for(int j = 1; j<= n; j++){
                if(s[i-1] == t[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else 
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return memo[n][n];
    }
};