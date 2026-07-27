// Last updated: 7/27/2026, 9:57:24 AM
1class Solution {
2    public void reverseString(char[] s) {
3        int length = s.length;
4        for(int i = 0 ; i < length / 2; i++){
5            char temp = s[i];
6            s[i] = s[length-i-1];
7            s[length-i-1] = temp;
8        }
9    }
10}