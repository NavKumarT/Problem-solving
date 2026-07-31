# Last updated: 7/31/2026, 1:26:24 PM
# Python Code
1class Solution:
2    def longestConsecutive(self, nums: List[int]) -> int:
3        numset = set({})
4        maxlength = 0
5        for num in nums:
6            numset.add(num)
7        for num in numset:
8            if num-1 not in numset:
9                count = 1
10                while num+count in numset:
11                    count += 1
12                maxlength = max(count, maxlength)
13        return maxlength
14