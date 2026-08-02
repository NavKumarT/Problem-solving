# Last updated: 8/2/2026, 1:05:40 PM
1class Solution:
2    def lengthOfLongestSubstring(self, s: str) -> int:
3        # using a variable length window 
4        left = 0
5        n = len(s)
6        if n == 0:
7            return 0
8        charset = defaultdict(int)
9        charset[s[0]] = 1
10        maxwindow = 1
11        for i in range(1, n):
12            charset[s[i]] += 1
13            while len(charset) < i-left+1:
14                charset[s[left]] -= 1
15                if charset[s[left]] == 0:
16                    charset.pop(s[left])
17                left += 1
18            maxwindow = max(maxwindow, len(charset))
19        return maxwindow
20
21