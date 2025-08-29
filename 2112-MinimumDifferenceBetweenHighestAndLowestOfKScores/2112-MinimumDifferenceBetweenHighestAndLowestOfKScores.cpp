// Last updated: 8/29/2025, 9:48:38 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n-k+1; i++)
            ans = min(ans, nums[i+k-1] - nums[i]);
        return ans;
    }
};