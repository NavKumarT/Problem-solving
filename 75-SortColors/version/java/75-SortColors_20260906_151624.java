// Last updated: 9/6/2026, 3:16:24 PM
1import java.util.Arrays;
2
3class Solution {
4    public static void sortColors(int[] nums) {
5        // low, mid and high
6        // mid marks the beginning of unknown
7        // high marks the end of unknowns
8        int low = 0, mid = 0, high = nums.length-1;
9        while(mid <= high) {
10            if(nums[mid] == 0){
11
12                int temp = nums[low];
13                nums[low] = nums[mid];
14                nums[mid] = temp;
15                low++;
16                mid++;
17            } else if(nums[mid] == 1) {
18                mid++;
19            } else {
20                int temp = nums[mid];
21                nums[mid] = nums[high];
22                nums[high] = temp;
23                high--;
24            }
25        }
26    }
27}