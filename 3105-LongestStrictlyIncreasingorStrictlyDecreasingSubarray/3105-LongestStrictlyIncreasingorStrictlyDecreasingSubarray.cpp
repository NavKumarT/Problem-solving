class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = 1;
        // int start = nums[0];
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                length++;
                ans = max(ans, length);
            }
            else {
                length = 1;
            }
        }
        length = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                length++;
                ans = max(ans, length);
            }
            else {
                length = 1;
            }
        }
        return ans;
    }
};