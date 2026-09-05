// Last updated: 9/5/2026, 12:27:32 PM
1class Solution {
2    public int findMaxConsecutiveOnes(int[] nums) {
3        int curr = 0, max = 0;
4        for(int i = 0; i < nums.length; i++) {
5            if(nums[i] == 1){
6                curr++;
7                max = Math.max(curr, max);
8            } else {
9                curr = 0;
10            }
11        }
12        return max;
13    }
14}