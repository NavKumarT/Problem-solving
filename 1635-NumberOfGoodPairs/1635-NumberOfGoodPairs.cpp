// Last updated: 8/29/2025, 9:49:02 PM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        int count = 0;
        for(auto it : mp)
            if(it.second > 1)
                count += it.second * (it.second - 1) / 2;
        return count;
    }
};