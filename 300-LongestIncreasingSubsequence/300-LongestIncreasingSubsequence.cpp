// Last updated: 8/29/2025, 9:51:08 PM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 1);
        for(int i = 1;  i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    memo[i] = max(memo[j]+1, memo[i]);
            }
        }
        int ans = 1;
        for(int i : memo)
            ans =  max(ans, i);
        return ans;
    }
};