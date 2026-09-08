// Last updated: 9/8/2026, 3:29:13 PM
1class Solution {
2    public int[] countBits(int n) {
3        int[] arr = new int[n+1];
4        for(int i = 1; i <= n; i++)
5            arr[i] = arr[i&(i-1)] + 1;
6        return arr;
7    }
8}