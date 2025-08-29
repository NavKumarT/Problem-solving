// Last updated: 8/29/2025, 9:47:51 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int leftMax = 0, dMax = 0;
        long long ans = 0;
        long long n = nums.size();
        for(long long k = 0; k < n; k++){
            ans = max(ans, (long long)(dMax) * (long long)(nums[k]));
            leftMax = max(leftMax, nums[k]);
            dMax = max(leftMax-nums[k], dMax);
        }
        return ans;
    }
};