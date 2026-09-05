// Last updated: 9/5/2026, 5:47:09 PM
1class Solution {
2    public int search(int[] nums, int target) {
3        int low = 0, high = nums.length-1;
4        while(low <= high) {
5            int mid = low + (high-low) / 2;
6            if(nums[mid] == target) {
7                return mid;
8            } else {
9                if(nums[mid] >= nums[low]) {
10                    if(target >= nums[low] && target <= nums[mid]){
11                        high = mid-1;
12                    } else {
13                        low = mid+1;
14                    }
15                } else {
16                    if(target > nums[mid] && target <= nums[high]) {
17                        low = mid+1;
18                    } else {
19                        high = mid-1;
20                    }
21                }
22            }
23        }
24        return -1;
25    }
26}