# Last updated: 7/30/2026, 7:30:10 PM
1class Solution:
2    def removeElement(self, nums: List[int], val: int) -> int:
3        left = 0
4        right = len(nums)-1
5        while left <= right:
6            while left <= right and nums[left] != val:
7                left += 1
8            while left <= right and nums[right] == val:
9                right -= 1
10            if left < right:
11                temp = nums[left]
12                nums[left] = nums[right]
13                nums[right] = temp
14        return right+1
15        