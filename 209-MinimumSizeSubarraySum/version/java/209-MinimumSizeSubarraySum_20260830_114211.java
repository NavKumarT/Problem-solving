// Last updated: 8/30/2026, 11:42:11 AM
1class Solution {
2    public int minSubArrayLen(int target, int[] nums) {
3        int start = 0;
4        int currentSum = 0;
5        int minWindow = Integer.MAX_VALUE;
6
7        for (int end = 0; end < nums.length; end++) {
8            currentSum += nums[end];
9
10            while (currentSum >= target) {
11                minWindow = Math.min(minWindow, end - start + 1);
12                currentSum -= nums[start++];
13            }
14        }
15
16        return minWindow == Integer.MAX_VALUE ? 0 : minWindow;
17    }
18}