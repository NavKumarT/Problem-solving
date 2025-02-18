class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i : nums)
            freq[i]++;
        vector<vector<int>> result;
        vector<int> currentResult;
        // unordered_set
        findAllPossiblePermutations(freq, currentResult, result, nums);
        return result;
    }

    void findAllPossiblePermutations(unordered_map<int, int> &mp, vector<int> &currentResult, vector<vector<int>> &result, vector<int> &nums){
        if(currentResult.size() == nums.size()){
            result.push_back(currentResult);
            return;
        }

        for(auto it : mp){
            if(it.second > 0){
                mp[it.first] -= 1;
                currentResult.push_back(it.first);
                findAllPossiblePermutations(mp, currentResult, result, nums);
                currentResult.pop_back();
                mp[it.first]++;
            }
        }
    }
};