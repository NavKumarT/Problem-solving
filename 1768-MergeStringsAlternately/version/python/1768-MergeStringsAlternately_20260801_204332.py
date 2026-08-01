# Last updated: 8/1/2026, 8:43:32 PM
1class Solution:
2    def mergeAlternately(self, word1: str, word2: str) -> str:
3        m = len(word1)
4        n = len(word2)
5        merged = ""
6        i, j = 0, 0 
7        first = True
8        while i < m and j < n:
9            if first:
10                merged += word1[i]
11                i += 1
12            else:
13                merged += word2[j]
14                j += 1
15            first = not first
16        while i < m:
17            merged += word1[i]
18            i += 1
19        while j < n:
20            merged += word2[j]
21            j += 1
22        return merged