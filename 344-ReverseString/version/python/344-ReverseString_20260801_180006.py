# Last updated: 8/1/2026, 6:00:06 PM
1class Solution:
2    def reverseString(self, s: List[str]) -> None:
3        """
4        Do not return anything, modify s in-place instead.
5        """
6        for i in range(0, len(s) // 2):
7            temp = s[i]
8            s[i] = s[len(s)-i-1]
9            s[len(s)-i-1] = temp
10        
11        