// Last updated: 9/8/2026, 3:19:14 PM
1class Solution {
2    public int[] countBits(int n) {
3        int[] arr = new int[n+1];
4        for(int i = 0; i <= n; i++)
5            arr[i] = countSetBits(i);
6        return arr;
7    }
8    
9    private int countSetBits(int n) {
10        int count = 0;
11        while(n > 0) {
12            n = n  & (n-1);
13            count++;
14        }
15        return count;
16    }
17}