// Last updated: 8/29/2025, 9:49:48 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int psum = 0;
        int count = 0;
        for(int num : nums){
            psum += num;
            if(psum == goal)
                count++;
            if(mp.find(psum-goal) != mp.end())
                count += mp[psum-goal];
            mp[psum]++;
        }
        return count;
    }
};