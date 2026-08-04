# Last updated: 8/4/2026, 11:07:27 PM
1class Solution:
2    def searchInsert(self, nums: List[int], target: int) -> int:
3        low, high = 0, len(nums)-1
4        floor, ceil = -1, len(nums)-1
5        while low <= high:
6            mid = low + (high-low)//2
7            if nums[mid] == target:
8                return mid
9            elif nums[mid] < target:
10                floor = mid
11                low = mid+1
12            else:
13                ceil = mid
14                high = mid-1
15        return floor+1