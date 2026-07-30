// Last updated: 7/30/2026, 10:51:33 AM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        // single pass approach 
5        unordered_map<int, int> mp;
6        for(int i = 0; i < nums.size(); i++){
7            if(mp.find(target-nums[i]) != mp.end())
8                return {i, mp[target-nums[i]]};
9            mp[nums[i]] = i;
10        }
11        return {-1, -1};
12    }
13};