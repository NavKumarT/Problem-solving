// Last updated: 8/29/2025, 9:50:43 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, curr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(curr, ans);
        return ans;
    }
};