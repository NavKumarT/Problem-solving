# Last updated: 8/2/2026, 1:26:23 PM
1class Solution:
2    def lengthOfLongestSubstring(self, s: str) -> int:
3        # using a variable length window 
4        left = 0
5        n = len(s)
6        if n == 0:
7            return 0
8        charset = defaultdict(int)
9        charset[s[0]] = 0
10        maxwindow = 1
11        for i in range(1, n):
12            if s[i] in charset and charset[s[i]] >= left:
13                left = charset[s[i]]+1
14            charset[s[i]] = i
15            maxwindow = max(maxwindow, i-left+1)
16        return maxwindow
17
18