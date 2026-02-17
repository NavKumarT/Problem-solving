// Last updated: 2/17/2026, 8:20:41 PM
1class Solution {
2public:
3    string reverseStr(string s, int k) {
4        int start = 0, end = 0;
5        int n = s.length();
6        for(int i = 0; i < s.length(); i+=2*k){
7            int end = i+k-1 >= n ? n-1 : i+k-1;
8            reverse(s, i, end);
9        }
10        return s;
11    }
12
13    void reverse(string &s, int start, int end){
14        while(start <= end){
15            swap(s[start++], s[end--]);
16        }
17    }
18};