// Last updated: 6/29/2026, 12:38:03 PM
1
2
3class Solution {
4public:
5    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
6        vector<vector<int>> ans;
7        vector<int> temp;
8        int start = 0;
9        sort(candidates.begin(), candidates.end());
10        backtracking(candidates, target, ans, temp, start);
11        return ans;
12    }
13
14    void backtracking(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int start){
15        if(target == 0){
16            ans.push_back(temp);
17            return;
18        }
19
20        for(int i = start; i < candidates.size(); i++){
21            if(candidates[i] > target)
22                continue;
23            if(i > start && candidates[i] == candidates[i-1])
24                continue;
25            temp.push_back(candidates[i]);
26            backtracking(candidates, target-candidates[i], ans, temp, i+1);
27            temp.pop_back();
28        }
29    }
30};