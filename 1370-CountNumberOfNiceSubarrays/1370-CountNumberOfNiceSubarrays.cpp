// Last updated: 8/29/2025, 9:49:19 PM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, start = 0, end = 0, curr = 0;
        unordered_map<int, int> mp;
        int psum = 0;
        for(int i = 0; i < nums.size(); i++){
            psum += (nums[i]%2 != 0);
            if(psum == k)
                count++;
            if(mp.find(psum-k) != mp.end())
                count += mp[psum-k];
            mp[psum]++;
        }
        return count;
    }
};