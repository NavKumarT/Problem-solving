// Last updated: 8/29/2025, 9:53:01 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ans = nums[0], curr = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr = max(curr + nums[i], nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};