// Last updated: 8/29/2025, 9:53:04 PM
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        backtracking(curr, ans, mp, nums);
        return ans;
    }

    void backtracking(vector<int> curr, vector<vector<int>> &ans, unordered_map<int, int> &mp, vector<int> &nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(auto& [num, freq] : mp){
            if(freq <= 0)
                continue;
            mp[num]--;
            curr.push_back(num);
            backtracking(curr, ans, mp, nums);
            mp[num]++;
            curr.pop_back();
        }
    }
};