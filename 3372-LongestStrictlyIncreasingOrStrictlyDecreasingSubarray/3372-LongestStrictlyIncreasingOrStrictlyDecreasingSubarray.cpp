// Last updated: 8/29/2025, 9:47:45 PM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxDecreasing = 1, maxIncreasing = 1;
        int ans = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                maxIncreasing++;
                maxDecreasing = 1;
                ans = max(maxIncreasing, ans);
            } else if(nums[i] < nums[i-1]){
                maxDecreasing++;
                maxIncreasing = 1;
                ans = max(maxDecreasing, ans);
            } else {
                maxIncreasing = 1;
                maxDecreasing = 1;
            }
        }
        return ans;
    }
};