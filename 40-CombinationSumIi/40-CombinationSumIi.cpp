// Last updated: 8/29/2025, 9:53:07 PM
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int currsum = 0, i = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(curr, ans, candidates, target, currsum, i);
        return ans;
    }


    void backtracking(vector<int> curr, vector<vector<int>> &ans, vector<int> candidates, int target, int currsum, int i){
        if(currsum == target){
            ans.push_back(curr);
            return;
        }

        if(currsum > target || i >= candidates.size())
            return;

        for(int k = i ; k < candidates.size(); k++){
            currsum += candidates[k];
            curr.push_back(candidates[k]);
            backtracking(curr, ans, candidates, target, currsum, k+1);
            curr.pop_back();
            currsum -= candidates[k];
            while(k+1 < candidates.size() && candidates[k+1] == candidates[k])
                k++;
        }
    }
};