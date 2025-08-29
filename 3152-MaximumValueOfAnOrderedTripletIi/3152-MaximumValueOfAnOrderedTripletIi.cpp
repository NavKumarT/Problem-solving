// Last updated: 8/29/2025, 9:47:52 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int imax = 0, dmax = 0;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, (long long)dmax * nums[i]);
            imax = max(imax, nums[i]);
            dmax = max(dmax, imax-nums[i]);
        }
        return ans;
    }
};