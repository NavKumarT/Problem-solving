class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> s;
        vector<vector<int>> res;
        vector<int> currentRes;
        findAllPossibleSolutions(res, s, nums, currentRes);
        return res;
    }

    void findAllPossibleSolutions(vector<vector<int>> &res, unordered_set<int> &s, vector<int> nums, vector<int> &currentRes){
        if(currentRes.size() == nums.size()){
            res.push_back(currentRes);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                currentRes.push_back(nums[i]);
                s.insert(nums[i]);
                findAllPossibleSolutions(res, s,  nums, currentRes);
                s.erase(nums[i]);
                currentRes.pop_back();
            }
        }
    }
};