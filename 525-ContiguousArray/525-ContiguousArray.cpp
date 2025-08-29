// Last updated: 8/29/2025, 9:50:37 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        if(nums[0] == 0)
            nums[0] = -1;
        mp[nums[0]] = 0;
        int psum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0)
                nums[i] = -1;
            psum = nums[i] + psum;
            if(psum == 0)
                ans = max(i+1, ans);
            if(mp.find(psum) != mp.end())
                ans = max(i-mp[psum], ans);
            else 
                mp[psum] = i;
        }
        return ans;
    }
};