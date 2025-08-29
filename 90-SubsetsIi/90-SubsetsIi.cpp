// Last updated: 8/29/2025, 9:52:41 PM
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        int n = nums.size();
        backtracking(curr, ans, i, n, nums);
        return ans;
    }

    void backtracking(vector<int> curr, vector<vector<int>> &ans, int i, int n, vector<int> &nums){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        if(i > n)
            return;
        curr.push_back(nums[i]);
        backtracking(curr, ans, i+1, n, nums);
        curr.pop_back();
        while(i+1 < n && nums[i+1] == nums[i])
            i++;
        backtracking(curr, ans, i+1, n, nums);
    }
};