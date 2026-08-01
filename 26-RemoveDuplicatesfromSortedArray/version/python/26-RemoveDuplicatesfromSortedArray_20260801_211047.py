# Last updated: 8/1/2026, 9:10:47 PM
1class Solution:
2    def removeDuplicates(self, nums: List[int]) -> int:
3        last = nums[0]
4        lastIndex = 0
5        n = len(nums)
6        for i in range(1, len(nums)):
7            if nums[i] == last:
8                continue
9            else:
10                nums[lastIndex+1] = nums[i]
11                lastIndex = lastIndex+1
12                last = nums[i]
13        return lastIndex+1
14        