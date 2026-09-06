// Last updated: 9/6/2026, 10:23:40 AM
1class Solution {
2    public int findDuplicate(int[] nums) {
3        int n = nums.length;
4        for(int num : nums) {
5            if(nums[Math.abs(num)-1] < 0) {
6                return Math.abs(num);
7            } else {
8                nums[Math.abs(num)-1] *= -1;
9            }
10        }
11        return -1;
12    }
13}