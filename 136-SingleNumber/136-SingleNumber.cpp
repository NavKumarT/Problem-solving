// Last updated: 8/29/2025, 9:52:13 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums)
            ans ^= num;
        return ans;
    }
};