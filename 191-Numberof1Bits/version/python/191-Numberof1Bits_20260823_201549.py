# Last updated: 8/23/2026, 8:15:49 PM
1class Solution:
2    def hammingWeight(self, n: int) -> int:
3        count = 0
4        while n > 0:
5            if n & 1:
6                count += 1
7            n = n >> 1
8        return count