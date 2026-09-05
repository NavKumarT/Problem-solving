// Last updated: 9/5/2026, 5:19:22 PM
1class Solution {
2    public int[] searchRange(int[] nums, int target) {
3        int first = firstOccurence(nums, target);
4        int last = lastOccurence(nums, target);
5        return new int[]{first, last};
6    }
7    
8    private int lastOccurence(int[] nums, int target) {
9        int start = 0, end = nums.length-1;
10        while(start <= end) {
11            int mid = start + (end-start) / 2;
12            if(nums[mid] > target) {
13                end = mid-1;
14            } else if(nums[mid] < target) {
15                start = mid+1;
16            } else {
17                if(mid == end || nums[mid] != nums[mid+1])
18                    return mid;
19                else 
20                    start = mid+1;
21            }
22        }
23        return -1;
24    }
25
26    private int firstOccurence(int[] nums, int target) {
27        int start = 0, end = nums.length-1;
28        while(start <= end) {
29            int mid = start + (end-start) / 2;
30            if(nums[mid] > target) {
31                end = mid-1;
32            } else if(nums[mid] < target) {
33                start = mid+1;
34            } else {
35                if(mid == 0 || nums[mid] != nums[mid-1])
36                    return mid;
37                else
38                    end = mid-1;
39            }
40        }
41        return -1;
42    }
43}