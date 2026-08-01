# Last updated: 8/1/2026, 6:19:56 PM
1class Solution:
2    def isPalindrome(self, s: str) -> bool:
3        n = len(s)
4        start = 0
5        end = n-1
6        while start < end:
7            while start < end and not s[start].isalnum():
8                start += 1
9            while start < end and not s[end].isalnum():
10                end -= 1
11            if start >= end:
12                return True
13            if s[start].lower() != s[end].lower():
14                return False
15            start += 1
16            end -= 1
17        return True
18        
19        