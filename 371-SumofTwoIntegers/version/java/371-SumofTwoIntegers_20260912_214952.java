// Last updated: 9/12/2026, 9:49:52 PM
1class Solution {
2    public int getSum(int a, int b) {
3        while(b != 0) {
4            int carry = (a&b) << 1;
5            a = a ^ b;
6            b = carry;
7        }
8        return a;
9    }
10}