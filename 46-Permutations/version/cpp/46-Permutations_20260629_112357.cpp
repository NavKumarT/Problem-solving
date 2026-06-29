// Last updated: 6/29/2026, 11:23:57 AM
1class Solution {
2public:
3    vector<vector<int>> permute(vector<int>& nums) {
4        vector<int> temp;
5        int index = 0;
6        vector<vector<int>> ans;
7        unordered_set<int> s; // track unique elements since we need to permute and not reuse 
8        backtracking(temp, ans, nums, s);
9        return ans;
10    }
11
12    void backtracking(vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums, unordered_set<int> &hashmap){
13        if(temp.size() == nums.size()){
14            ans.push_back(temp);
15            return;
16        }
17        for(int i = 0; i < nums.size(); i++){
18            if(hashmap.find(nums[i]) != hashmap.end()){
19                continue; 
20            }
21            temp.push_back(nums[i]);
22            hashmap.insert(nums[i]);
23            backtracking(temp, ans, nums, hashmap);
24            temp.pop_back();
25            hashmap.erase(nums[i]);
26        }
27    }
28};