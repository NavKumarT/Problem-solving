# Last updated: 8/2/2026, 11:29:16 AM
1class Solution:
2    def maxArea(self, height: List[int]) -> int:
3        left, right = 0, len(height)-1
4        max_area = 0
5        while left < right:
6            curr = (right-left) * min(height[left], height[right])
7            max_area = max(curr, max_area)
8            if height[left] < height[right]:
9                left += 1
10            else:
11                right -= 1
12        return max_area