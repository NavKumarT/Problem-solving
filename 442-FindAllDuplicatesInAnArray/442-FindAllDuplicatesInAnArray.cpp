// Last updated: 8/29/2025, 9:50:49 PM
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[abs(nums[i])-1] < 0)
                ans.push_back(abs(nums[i]));
            else 
                nums[abs(nums[i])-1] = nums[abs(nums[i])-1] * -1;
        }
        return ans;
    }
};