class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentResult;
        int sum = 0;
        int n = candidates.size();
        func(ans, currentResult, sum, target, n, candidates, 0);
        return ans;
    }

    void func(vector<vector<int>> &ans, vector<int> &currRes, int &sum, int &target,int n, vector<int> candidates, int i){
        if(sum == target){
            ans.push_back(currRes);
            return;
        }

        if(sum > target || i >= n)
            return;

        currRes.push_back(candidates[i]);
        sum += candidates[i];
        func(ans, currRes, sum, target, n, candidates, i);
        sum -= candidates[i];
        currRes.pop_back();            
        func(ans, currRes, sum, target, n, candidates, i+1);
    }
};