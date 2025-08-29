// Last updated: 8/29/2025, 9:51:18 PM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        if(k >= nums.size())
            k = nums.size()-1;
        for(int i = 0; i <= k && i < nums.size(); i++)
            s.insert(nums[i]);
        if(s.size() < k+1)
            return true;
        for(int i = k+1; i < nums.size(); i++){
            s.erase(nums[i-k-1]);
            s.insert(nums[i]);
            if(s.size() < k+1)
                return true;
        }
        return false;
    }
};