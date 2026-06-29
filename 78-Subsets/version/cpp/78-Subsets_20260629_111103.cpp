// Last updated: 6/29/2026, 11:11:03 AM
1class Solution {
2public:
3    vector<vector<int>> subsets(vector<int>& nums) {
4        vector<int> temp;
5        vector<vector<int>> ans;
6        int i = 0;
7        int n = nums.size();
8        backtracking(temp, ans, nums, i, n);
9        return ans;
10    }
11
12    void backtracking(vector<int> temp, vector<vector<int>> &ans, vector<int> &nums, int index, int n){
13        if(index == n){
14            ans.push_back(temp);
15            return;
16        }
17        backtracking(temp, ans, nums, index+1, n);
18        temp.push_back(nums[index]);
19        backtracking(temp, ans, nums, index+1, n);
20    }
21};