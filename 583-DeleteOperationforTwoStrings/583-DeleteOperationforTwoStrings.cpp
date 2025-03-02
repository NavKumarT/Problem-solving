class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = dp(word1.length(), word2.length(), word1, word2);
        return (word1.length()-lcs) + (word2.length()-lcs);
    }

    int dp(int m, int n, string word1, string word2){
        vector<vector<int>> memo(m+1, vector<int> (n+1, 0));
        for(int i = 1; i<= m; i++){
            for(int j = 1; j<= n; j++){
                if(word1[i-1] == word2[j-1]){
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[m][n];
    }
};