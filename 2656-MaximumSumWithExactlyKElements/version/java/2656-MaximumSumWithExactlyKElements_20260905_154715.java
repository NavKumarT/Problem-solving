// Last updated: 9/5/2026, 3:47:15 PM
1class Solution {
2    public int maximizeSum(int[] nums, int k) {
3        int max = Integer.MIN_VALUE;
4        for(int num : nums) {
5            max = Math.max(max, num);
6        }
7        return max*k + (k *(k-1)/2);
8    }
9}
10
11
12// 5 + 6 2 * 5 + k-1
13
14// 5 + 6 + 7 3*5 + 