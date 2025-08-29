// Last updated: 8/29/2025, 9:49:53 PM
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // if two traversals to find if the element is either increasing or decreasing 
        // increasing  || decreasing  -> return true
        // requires 2 traversals 
        int order = 0;
        for(int i = 1; i < nums.size(); i++){
            if(order == 0){
                order = nums[i] - nums[i-1] > 0 ? 1 : nums[i] - nums[i-1] == 0 ? 0 : -1;
            } else if(order == -1){
                if(nums[i] > nums[i-1])
                    return false;
            } else if(order == 1){
                if(nums[i] < nums[i-1])
                   return false;
            }
        }
        return true;
    }
};