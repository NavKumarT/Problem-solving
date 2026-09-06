// Last updated: 9/6/2026, 12:54:17 PM
1class Solution {
2public static int findKthLargest(int[] nums, int k) {
3    int low = 0, high = nums.length-1, n = nums.length;
4    while(low <= high) {
5        int p = partition(nums, low, high);
6        if(p == n-k) {
7            return nums[p];
8        } else if(p > n-k) {
9            high = p - 1;
10        } else {
11            low = p+1;
12        }
13    }
14        return -1;
15    }
16
17private static int partition(int[] nums, int low, int high) {
18    int pivot = nums[high];
19    int j = low-1;
20    for(int i = low; i <= high-1; i++) {
21        if(nums[i] < pivot) {
22            j++;
23            int temp = nums[i];
24            nums[i] = nums[j];
25            nums[j] = temp;
26        }
27    }
28    int temp = nums[j+1];
29    nums[j+1] = pivot;
30    nums[high] = temp;
31    return j+1;
32}
33
34}
35