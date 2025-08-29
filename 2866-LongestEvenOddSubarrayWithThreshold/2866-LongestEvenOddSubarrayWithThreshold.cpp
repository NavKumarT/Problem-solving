// Last updated: 8/29/2025, 9:47:58 PM
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int k) {
        int curr = 0, maximum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(curr == 0){
                if(nums[i] <= k && nums[i] % 2 == 0){
                    curr++;
                    maximum = max(maximum, curr);
                } else {
                    continue;
                }
            } else {
                if(nums[i] <= k && ((nums[i-1] % 2 == 0 && nums[i] % 2 != 0) || (nums[i] % 2 == 0 && nums[i-1] % 2 != 0))){
                    curr++;
                    maximum = max(curr, maximum);
                } else if(nums[i] <= k && nums[i] % 2 == 0){
                    curr = 1;
                    continue;
                } else {
                    curr = 0;
                    continue;
                }
            }
        }
        return maximum;
    }
};