# Last updated: 8/2/2026, 11:45:51 AM
1class Solution:
2    def trap(self, height: List[int]) -> int:
3        n = len(height)
4        leftmax = [height[0]] * n
5        rightmax = [height[n-1]] * n
6        for i in range(1, n):
7            leftmax[i] = max(leftmax[i-1], height[i])
8        for i in range(n-2, -1, -1):
9            rightmax[i] = max(rightmax[i+1], height[i])
10        total = 0
11        for i in range(n):
12            total += min(leftmax[i], rightmax[i]) - height[i]
13        return total