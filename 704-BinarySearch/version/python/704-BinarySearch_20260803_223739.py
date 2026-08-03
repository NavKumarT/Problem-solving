# Last updated: 8/3/2026, 10:37:39 PM
1class Solution:
2    def search(self, nums: List[int], target: int) -> int:
3        low= 0
4        high= len(nums)-1
5        while low <= high:
6            mid = low + (high-low)//2
7            print(mid)
8            if nums[mid] == target:
9                return mid
10            elif nums[mid] < target:
11                low = mid+1
12            else:
13                high = mid-1
14        return -1