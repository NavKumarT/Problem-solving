// Last updated: 8/29/2025, 9:51:04 PM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        long long ans =  func(coins, amount, coins.size());
        if(ans == INT_MAX)
            return -1;
        else 
            return ans;
    }

    int func(vector<int> coins, int amount, int n){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= amount; ++j) {
            for (int i = 0; i < coins.size(); ++i) {
                if (coins[i] <= j) {
                    int res = dp[j-coins[i]];
                    if(res == INT_MAX)
                        continue;
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp.back() == INT_MAX)
            return -1;
        return dp.back();
    }
};