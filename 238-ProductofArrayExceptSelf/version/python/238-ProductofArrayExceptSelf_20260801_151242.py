# Last updated: 8/1/2026, 3:12:42 PM
1class Solution:
2    def productExceptSelf(self, nums: List[int]) -> List[int]:
3        suffix = [1] * len(nums)
4        s = 1
5        suffix[-1] = s
6        for i in range(len(nums)-2, -1, -1):
7            suffix[i] = s * nums[i+1]
8            s = suffix[i]
9        prefix = 1
10        ans = []
11        for i in range(0, len(nums)):
12            ans.append(prefix * suffix[i])
13            prefix = prefix * nums[i]
14        return ans
15