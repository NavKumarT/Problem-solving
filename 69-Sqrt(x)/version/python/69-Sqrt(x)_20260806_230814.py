# Last updated: 8/6/2026, 11:08:14 PM
1class Solution:
2    def mySqrt(self, x: int) -> int:
3        low = 0
4        high = x
5        floor = 1
6        while low <= high:
7            mid = low + (high-low)//2
8            if mid*mid == x:
9                return mid
10            elif mid*mid < x:
11                floor = mid
12                low = mid+1
13            else:
14                high = mid-1
15        return floor
16        