// Last updated: 3/6/2026, 8:32:35 PM
1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int x = 0;
5        for(int num : nums)
6            x = x ^ num;
7        return x;
8    }
9};