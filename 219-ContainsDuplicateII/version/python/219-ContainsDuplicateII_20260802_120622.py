# Last updated: 8/2/2026, 12:06:22 PM
1class Solution:
2    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
3        hashset = set({})
4        k = min(k, len(nums)-1)
5        for i in range(k+1):
6            hashset.add(nums[i])
7        if len(hashset) != k+1:
8            return True
9        for i in range(k+1, len(nums)):
10            hashset.discard(nums[i-k-1])
11            hashset.add(nums[i])
12            if len(hashset) != k+1:
13                return True
14        return False