// Last updated: 8/29/2025, 9:47:44 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        for(int i = 1; i < nums.size(); i++){
            if((nums[i] % 2 == 0 && nums[i-1] % 2 != 0 || (nums[i] % 2 != 0 && nums[i-1] % 2 == 0)))
                continue;
            else 
                return false;
        }
        return true;
    }
};