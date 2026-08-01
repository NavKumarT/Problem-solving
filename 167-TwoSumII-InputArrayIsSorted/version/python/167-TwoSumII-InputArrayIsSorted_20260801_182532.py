# Last updated: 8/1/2026, 6:25:32 PM
1class Solution:
2    def twoSum(self, numbers: List[int], target: int) -> List[int]:
3        n = len(numbers)
4        low = 0
5        high = n-1
6        while low < high:
7            current = numbers[low] + numbers[high]
8            if current > target:
9                high -= 1
10            elif current < target:
11                low += 1
12            else: 
13                return [low+1, high+1]
14        return [-1, -1]
15        