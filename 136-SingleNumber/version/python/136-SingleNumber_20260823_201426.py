# Last updated: 8/23/2026, 8:14:26 PM
1class Solution:
2    def singleNumber(self, nums: List[int]) -> int:
3        xor = 0
4        for num in nums:
5            xor ^= num
6        return xor