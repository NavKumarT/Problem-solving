// Last updated: 7/30/2026, 12:24:36 PM
1class Solution {
2    public int[] getConcatenation(int[] nums) {
3        int size = nums.length;
4        int ans[] = new int[size*2];
5        for(int i = 0; i < size; i++)
6            ans[i] = ans[size+i] = nums[i];
7        return ans;
8    }
9}