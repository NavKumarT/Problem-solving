# Last updated: 8/1/2026, 10:44:50 PM
1class Solution:
2    def threeSum(self, nums: list[int]) -> list[list[int]]:
3        nums.sort()
4        ans = []
5        for i in range(0, len(nums)-2):
6            if i > 0 and nums[i] == nums[i-1]:
7                continue
8            target = -1 * nums[i]
9            low = i+1
10            high = len(nums)-1
11            while low < high:
12                current  = nums[low] + nums[high]
13                if current == target:
14                    ans.append([nums[i], nums[low], nums[high]])
15                    low += 1
16                    high -= 1
17                    while low < high and (nums[low] == nums[low-1]):
18                        low += 1
19                    while low < high and (nums[high] == nums[high+1]):
20                        high -= 1
21                elif current > target:
22                    high -= 1
23                else:
24                    low += 1
25        return ans
26