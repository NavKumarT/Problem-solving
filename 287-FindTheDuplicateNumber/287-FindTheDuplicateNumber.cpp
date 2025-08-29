// Last updated: 8/29/2025, 9:51:06 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num : nums){
            if(nums[abs(num)-1] < 0)
                return abs(num);
            nums[abs(num)-1] = -1 * nums[abs(num)-1];
        }
        return -1;
    }
};