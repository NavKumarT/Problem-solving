# Last updated: 8/1/2026, 8:59:49 PM
1class Solution:
2    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
3        """
4        Do not return anything, modify nums1 in-place instead.
5        """
6        # find the largest element from either array and place it at the end 
7        length = len(nums1)
8        i = m-1
9        j = n-1
10        end = length-1
11        while i >= 0 and j >= 0:
12            if nums1[i] >= nums2[j]:
13                nums1[end] = nums1[i]
14                i -= 1
15            else:
16                nums1[end] = nums2[j]
17                j -= 1
18            end -= 1
19        while i >= 0:
20            nums1[end] = nums1[i]
21            i -= 1
22            end -= 1
23        while j >= 0:
24            nums1[end] = nums2[j]
25            j -= 1
26            end -= 1
27        
28
29        