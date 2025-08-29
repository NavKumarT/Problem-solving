// Last updated: 8/29/2025, 9:48:51 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n])
                count++;
            if(count > 1)
                return false;
        }
        return true;
    }
};