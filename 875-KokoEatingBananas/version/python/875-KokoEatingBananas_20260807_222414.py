# Last updated: 8/7/2026, 10:24:14 PM
1class Solution:
2    def minEatingSpeed(self, piles: List[int], h: int) -> int:
3        low, high = 1, float('-inf')
4        ans = float('inf')
5        speed = -1
6        for pile in piles: 
7            high = max(pile, high)
8        def calculateHours(speed: int) -> int:
9            total = 0
10            for pile in piles:
11                if pile <= speed:
12                    total += 1
13                else:
14                    total += ceil(pile/speed)
15            return total
16        while low <= high:
17            mid = low + (high-low)//2
18            if calculateHours(mid) <= h:
19                speed = mid
20                high = mid-1
21            else:
22                low =mid+1
23        return speed
24
25