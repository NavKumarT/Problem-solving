// Last updated: 8/29/2025, 9:48:42 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        return nums;
    }
};