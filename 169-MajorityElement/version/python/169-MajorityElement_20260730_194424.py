# Last updated: 7/30/2026, 7:44:24 PM
1class Solution:
2    def majorityElement(self, nums: List[int]) -> int:
3        element = nums[0]
4        count = 1
5        for i in range(1, len(nums)):
6            if element == nums[i]:
7                count += 1
8                continue
9            count -= 1
10            if count == 0:
11                element = nums[i]
12                count = 1
13        return element