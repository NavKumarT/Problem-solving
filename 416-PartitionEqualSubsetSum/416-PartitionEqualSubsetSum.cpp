// Last updated: 8/29/2025, 9:50:51 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 != 0)
            return false;
        return helper(nums, 0, n, sum/2, 0);
    }

    bool helper(vector<int> nums, int i, int n, int sum, int curr){
        vector<vector<bool>> memo(n+1, vector<bool> (sum+1, false));
        for(int i = 0; i <= n; i++)
            memo[i][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(j-nums[i-1] >= 0)
                memo[i][j] = memo[i-1][j-nums[i-1]] || memo[i-1][j];
                else 
                memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][sum];
    }
};