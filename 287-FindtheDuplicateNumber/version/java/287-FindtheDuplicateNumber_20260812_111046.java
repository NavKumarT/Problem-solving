// Last updated: 8/12/2026, 11:10:46 AM
1class Solution {
2    public int findDuplicate(int[] nums) {
3        for(int num : nums){
4            if(nums[Math.abs(num)-1] < 0){
5                return Math.abs(num);
6            }
7            nums[Math.abs(num)-1] *= -1;
8        }
9        return -1;
10    }
11}