// Last updated: 2/15/2026, 9:51:03 AM
1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int ans = 0;
5        for(int num : nums)
6        ans = ans ^ num;
7        for(int i = 0; i <= nums.size(); i++)
8            ans = ans ^ i;
9        return ans;
10    }
11};