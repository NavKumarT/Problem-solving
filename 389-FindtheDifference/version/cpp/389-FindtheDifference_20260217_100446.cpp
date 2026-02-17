// Last updated: 2/17/2026, 10:04:46 AM
1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        int n = 0;
5        for(char ch : s)
6            n = n ^ (ch-'a');
7        for(char ch : t)
8            n = n ^ (ch - 'a');
9        return char(n + 'a');
10    }
11};