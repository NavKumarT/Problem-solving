// Last updated: 6/29/2026, 12:34:34 PM
1class Solution {
2public:
3    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
4        vector<vector<int>> ans;
5        vector<int> temp;
6        int start = 0;
7        backtracking(candidates, target, ans, temp, start);
8        return ans;
9    }
10
11    void backtracking(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int start){
12        if(target == 0){
13            ans.push_back(temp);
14            return;
15        }
16
17        for(int i = start; i < candidates.size(); i++){
18            if(candidates[i] > target)
19                continue;
20            target = target - candidates[i];
21            temp.push_back(candidates[i]);
22            backtracking(candidates, target, ans, temp, i);
23            target = target + candidates[i];
24            temp.pop_back();
25        }
26    }
27};