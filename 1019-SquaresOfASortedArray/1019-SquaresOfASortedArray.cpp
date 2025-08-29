// Last updated: 8/29/2025, 9:49:42 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans; 
        int low = 0, n = nums.size(), high = n-1;
        while(low <= high){
            if(abs(nums[low]) >= abs(nums[high])){
                ans.push_back(nums[low]*nums[low]);
                low++;
            } else {
                ans.push_back(nums[high]*nums[high]);
                high--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};