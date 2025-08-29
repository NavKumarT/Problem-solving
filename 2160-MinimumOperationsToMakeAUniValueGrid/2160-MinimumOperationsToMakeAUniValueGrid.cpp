// Last updated: 8/29/2025, 9:48:36 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        if(grid.size() == 1 && grid[0].size() == 1)
            return 0;
        for(auto v : grid){
            for(int num : v){
                nums.push_back(num);
            }
        }
        int count = 0;
        nth_element(nums.begin(),nums.begin()+nums.size()/2, nums.end());
        int target = nums[nums.size()/2];
        for(int num : nums){
            if(num % x != target % x)
                return -1;
            count += abs(num-target)/x;
        }
        return count;
    }
};