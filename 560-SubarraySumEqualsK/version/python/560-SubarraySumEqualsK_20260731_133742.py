# Last updated: 7/31/2026, 1:37:42 PM
1class Solution:
2    def subarraySum(self, nums: List[int], k: int) -> int:
3        prefix_sum_set = defaultdict(int)
4        prefix_sum = 0
5        count = 0
6        for num in nums:
7            prefix_sum += num
8            complement_prefix_sum = prefix_sum - k
9            if complement_prefix_sum in prefix_sum_set:
10                count += prefix_sum_set[complement_prefix_sum]
11            if prefix_sum == k:
12                count += 1
13            prefix_sum_set[prefix_sum] += 1
14        return count
15