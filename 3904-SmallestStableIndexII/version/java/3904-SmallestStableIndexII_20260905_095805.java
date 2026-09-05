// Last updated: 9/5/2026, 9:58:05 AM
1
2
3class Solution {
4    public int firstStableIndex(int[] nums, int k) {
5        int[] pre = new int[nums.length];
6        pre[nums.length-1] = nums[nums.length-1];
7        int idx = nums.length-2;
8        while(idx >= 0){
9            pre[idx] = Math.min(pre[idx+1], nums[idx]);
10            idx--;
11        }
12        int max = nums[0];
13        for(int  i = 0 ; i < nums.length; i++){
14            max = Math.max(max, nums[i]);
15            if(max-pre[i] <= k){
16                return i;
17            }
18        }
19        return -1;
20    }
21}