// Last updated: 6/29/2026, 12:06:10 PM
1class Solution {
2public:
3    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
4        vector<int> subset;
5        vector<vector<int>> ans;
6        int start = 0;
7        sort(nums.begin(), nums.end());
8        backtracking(subset, ans, nums, start);
9        return ans;
10    }
11
12    void backtracking(vector<int> &subset, vector<vector<int>> &ans, vector<int> &nums, int start){
13        ans.push_back(subset);
14
15        for(int i = start; i < nums.size(); i++){
16            if(i > start && nums[i] == nums[i-1]){
17                continue;
18            }
19            subset.push_back(nums[i]);
20            backtracking(subset, ans, nums, i+1);
21            subset.pop_back();
22
23        }
24    }
25};