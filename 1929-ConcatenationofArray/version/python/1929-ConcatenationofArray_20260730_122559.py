# Last updated: 7/30/2026, 12:25:59 PM
1class Solution:
2    def getConcatenation(self, nums: List[int]) -> List[int]:
3        length = len(nums)
4        for i in range(length):
5            nums.append(nums[i])
6        return nums
7        