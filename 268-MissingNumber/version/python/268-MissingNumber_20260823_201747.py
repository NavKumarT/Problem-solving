# Last updated: 8/23/2026, 8:17:47 PM
1class Solution:
2    def missingNumber(self, nums: List[int]) -> int:
3        xor = 0
4        for num in nums:
5            xor ^= num
6        for i in range(len(nums)+1):
7            xor ^= i
8        return xor