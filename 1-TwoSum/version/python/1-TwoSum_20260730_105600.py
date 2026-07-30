# Last updated: 7/30/2026, 10:56:00 AM
1class Solution:
2    def twoSum(self, nums: List[int], target: int) -> List[int]:
3        hashmap = {}
4        for i, num in enumerate(nums):
5            complement = target - num
6            if complement in hashmap:
7                return [i, hashmap[complement]]
8            hashmap[num] = i
9        return [-1, -1]
10        