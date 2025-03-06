class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return func(coins, coins.size(), amount);
    }

    long long unsigned int func(vector<int> coins, int n, int amount){
        vector<vector<long long unsigned int>> memo(n+1, vector<long long unsigned int>(amount+1, 0));
        for(int i = 0; i <= n; i++)
            memo[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                memo[i][j] = memo[i-1][j];
                if(j-coins[i-1] >= 0)
                memo[i][j] += memo[i][j-coins[i-1]];
            }
        }
        return memo[n][amount];
        // if(amount == 0)
        // return 1;
        // if(n == 0 || amount < 0)
        //     return 0;
        // return func(coins, n-1, amount) + func(coins, n, amount-coins[n-1]);
    }
};