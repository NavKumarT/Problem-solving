// Last updated: 8/29/2025, 9:48:14 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
                
            }
        }

    vector<int> ans(n, 0);
    int i = 0;
    for(int x : nums){
        if(x != 0){
            ans[i] = x;
            i++;
        }
    }
        return ans;

    }
};