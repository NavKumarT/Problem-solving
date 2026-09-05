// Last updated: 9/5/2026, 12:30:48 PM
1class Solution {
2    public int maxSubArray(int[] nums) {
3        int curr = nums[0], max = curr;
4        for(int i = 1; i < nums.length; i++){
5            curr = Math.max(nums[i], curr+nums[i]);
6            max = Math.max(curr, max);
7        }
8        return max;
9    }
10}