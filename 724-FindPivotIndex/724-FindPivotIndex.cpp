// Last updated: 8/29/2025, 9:50:18 PM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, psum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(psum == sum - psum - nums[i])
                return i;
            psum += nums[i];
        }
        return -1;
    }
};