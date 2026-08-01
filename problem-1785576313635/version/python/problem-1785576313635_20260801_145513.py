# Last updated: 8/1/2026, 2:55:13 PM
1class Solution:
2    def majorityElement(self, nums: List[int]) -> List[int]:
3        # at max we can have 2 elements appear n/3 times 
4        first, second = None, None
5        n = len(nums)
6        count1, count2 = 0, 0
7        for i in range(0, len(nums)):                
8            # check if the element is one of first or second
9            if first == nums[i]:
10                count1 += 1
11            elif second == nums[i]: 
12                count2 += 1
13            elif count1 == 0:
14                count1 = 1
15                first = nums[i]
16            elif count2 == 0:
17                count2 = 1
18                second = nums[i]
19            else:
20                count1 -= 1
21                count2 -= 1
22        ans = []
23        count1 = 0
24        count2 = 0
25        for num in nums:
26            if num == first:
27                count1 += 1
28            if num == second:
29                count2 += 1
30        if count1 > n/3:
31            ans.append(first)
32        if count2 > n/3:
33            ans.append(second)
34        return ans
35
36        