// Last updated: 8/29/2025, 9:49:50 PM
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
                int c = nums[0], maximumPositive = nums[0];
        for(int i = 1; i < n; i++){
            c = max(c + nums[i], nums[i]);
            maximumPositive = max(maximumPositive, c);
        }
        if(maximumPositive < 0)
            return maximumPositive;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            nums[i] = -1 * nums[i];
        }

        int curr = nums[0], maximumNegative = nums[0];
        for(int i = 1; i < n; i++){
            curr = max(curr + nums[i], nums[i]);
            maximumNegative = max(maximumNegative, curr);
        }
        return sum + maximumNegative > maximumPositive ?  sum + maximumNegative : maximumPositive;
    }
};