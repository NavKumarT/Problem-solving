# Last updated: 8/1/2026, 2:53:26 PM
1class Solution:
2    def majorityElement(self, nums: List[int]) -> List[int]:
3        # at max we can have 2 elements appear n/3 times 
4        first, second = None, None
5        n = len(nums)
6        count1, count2 = 0, 0
7        for i in range(0, len(nums)):                
8            # check if the element is one of first or second
9            if first == nums[i] or second == nums[i]:
10                if first == nums[i]:
11                    count1 += 1
12                else: 
13                    count2 += 1
14                continue
15            # check if either first or second is not set 
16            if count1 == 0 or count2 == 0:
17                if count1 == 0:
18                    count1 = 1
19                    first = nums[i]
20                else:
21                    count2 = 1
22                    second = nums[i]
23                continue
24            
25            count1 -= 1
26            count2 -= 1
27        ans = []
28        count1 = 0
29        count2 = 0
30        for num in nums:
31            if num == first:
32                count1 += 1
33            if num == second:
34                count2 += 1
35        if count1 > n/3:
36            ans.append(first)
37        if count2 > n/3:
38            ans.append(second)
39        return ans
40
41        