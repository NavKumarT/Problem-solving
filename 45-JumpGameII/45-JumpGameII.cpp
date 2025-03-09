class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, INT_MAX);
        memo[0] = 0;
        for(int i = 0; i < n ;i++){
            for(int j = i; j < n && j <= i+nums[i]; j++)
                memo[j] = min(memo[j], memo[i]+1);
        }
        return memo[n-1];
    }
};