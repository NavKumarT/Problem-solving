// Last updated: 8/29/2025, 9:48:29 PM
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<int> memo(questions.size()+1, -1);
        return dp(questions, questions.size(), 0, memo);
    }

    long long dp(vector<vector<int>> &questions, int n, int curr, vector<int> &memo){
        
        if(curr >= n)
            return 0;
        else if(memo[curr] != -1)
            return memo[curr];
        else 
            {
                long long ans = max(questions[curr][0] + dp(questions, n, curr+questions[curr][1]+1, memo), dp(questions, n, curr+1, memo));
        memo[curr] = ans;
        return ans;
            }
    }
};