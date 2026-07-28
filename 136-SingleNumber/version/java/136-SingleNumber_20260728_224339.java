// Last updated: 7/28/2026, 10:43:39 PM
1class Solution {
2    public int singleNumber(int[] nums) {
3                int x = 0;
4        for(int num : nums)
5            x ^= num;
6        return x;
7    }
8}