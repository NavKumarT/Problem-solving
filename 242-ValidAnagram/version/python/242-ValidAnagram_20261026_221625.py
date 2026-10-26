# Last updated: 10/26/2026, 10:16:25 PM
1class Solution:
2    def isAnagram(self, s: str, t: str) -> bool:
3        if len(s) != len(t):
4            return False
5        n = len(s)
6        count = [0] * 26
7        for i in range(n):
8            count[ord(s[i]) - ord('a')] += 1
9        for i in range(n):
10            count[ord(t[i]) - ord('a')] -= 1
11        for i in count:
12            if i != 0:
13                return False
14        return True