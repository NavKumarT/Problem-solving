// Last updated: 8/30/2026, 11:40:37 AM
1class Solution {
2    public int minSubArrayLen(int target, int[] nums) {
3        int start = 0, end = 0, current = nums[0];
4        int minWindow = nums.length+1;
5        for(int i = 1; i < nums.length; i++){
6            while(current  >= target && start <= end){
7                minWindow = Math.min(end-start+1, minWindow);
8                current -= nums[start++];
9            }
10            current += nums[i];
11            end = i;
12        }
13        while(current  >= target && start <= end){
14            minWindow = Math.min(end-start+1, minWindow);
15            current -= nums[start++];
16        }
17        return minWindow == nums.length+1 ? 0 : minWindow;
18    }
19}