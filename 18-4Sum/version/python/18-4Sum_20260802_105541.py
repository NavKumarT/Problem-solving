# Last updated: 8/2/2026, 10:55:41 AM
1class Solution:
2    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
3        ans = []
4        nums.sort()
5        i = 0
6        while i < len(nums)-3:
7            num = nums[i]
8            new = target - num
9            triplets = self.threeSum(nums[i+1: len(nums)], new)
10            for triple in triplets:
11                ans.append([nums[i]] + triple)
12            i += 1
13            while i < len(nums) and nums[i] == nums[i-1]:
14                i += 1
15        return ans
16
17    def threeSum(self, nums: list[int], t: int) -> list[list[int]]:
18        ans = []
19        for i in range(0, len(nums)-2):
20            if i > 0 and nums[i] == nums[i-1]:
21                continue
22            target = t - nums[i]
23            low = i+1
24            high = len(nums)-1
25            while low < high:
26                current  = nums[low] + nums[high]
27                if current == target:
28                    ans.append([nums[i], nums[low], nums[high]])
29                    low += 1
30                    high -= 1
31                    while low < high and (nums[low] == nums[low-1]):
32                        low += 1
33                    while low < high and (nums[high] == nums[high+1]):
34                        high -= 1
35                elif current > target:
36                    high -= 1
37                else:
38                    low += 1
39        return ans
40
41
42