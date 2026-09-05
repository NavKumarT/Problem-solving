// Last updated: 9/5/2026, 8:18:14 PM
1class Solution {
2    public static int findMin(int[] nums) {
3        int low = 0, high = nums.length-1;
4        while(low <= high) {
5            int mid = low + (high-low)/2;
6            if((mid == 0 || nums[mid] < nums[mid-1]) && (mid == nums.length -1 || nums[mid] < nums[mid+1]))
7                return nums[mid];
8            if(nums[low] <= nums[mid] && nums[high] < nums[low]) {
9                low = mid+1;
10            } else {
11                high = mid-1;
12            }
13        }
14        return -1;
15    }
16}