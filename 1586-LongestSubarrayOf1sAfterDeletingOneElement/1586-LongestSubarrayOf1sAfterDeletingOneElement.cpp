// Last updated: 8/29/2025, 9:49:06 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int zeroes = 0;
        int ones  = 0;
        int start = 0, end = 0;
        while(end < nums.size() && start  <= end){
            while(zeroes > 1){
                if(nums[start] == 0)
                    zeroes--;
                else 
                    ones--;
                start++;
            }
            ans = zeroes == 0 ? max(ans, ones-1) : max(ans, ones);
            if(nums[end] == 1)
                ones++;
            else 
                zeroes++;
            end++;
        }
        while(zeroes > 1){
                if(nums[start] == 0)
                    zeroes--;
                else 
                    ones--;
                start++;
            }
        ans = zeroes == 0 ? max(ans, ones-1) : max(ans, ones);
        return ans;
    }
};