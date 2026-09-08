// Last updated: 9/8/2026, 4:12:37 PM
1class Solution {
2    public int reverseBits(int n) { 
3        int ans = 0;
4        int i = 31;
5        while(i >= 0) {
6            ans = ans << 1;
7            ans = ans | (n & 1);
8            n = n >> 1;
9            i--;
10        }
11        return ans;
12    }
13}