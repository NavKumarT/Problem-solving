// Last updated: 9/6/2026, 11:19:49 AM
1import java.util.Arrays;
2
3class Solution {
4    public static int[] sortArray(int[] nums) {
5        return mergeSort(nums, 0, nums.length-1);
6    }
7
8    private static int[] mergeSort(int[] nums, int low, int high) {
9        if(low < high) {
10            int mid = low + (high-low)/2;
11            mergeSort(nums, low, mid);
12            mergeSort(nums,mid+1, high);
13            merge(nums, low, mid, high);
14        }
15        return nums;
16    }
17
18    private static void merge(int[] nums, int low, int mid, int high) {
19        int m = mid-low+1;
20        int n = high-mid;
21        int[] left = new int[m];
22        int[] right = new int[n];
23        for(int i = 0 ; i < m; i++) {
24            left[i] = nums[low+i];
25        }
26        for(int j = 0; j < n; j++) {
27            right[j] = nums[mid+j+1];
28        }
29
30
31        int i = 0, j = 0, k = low;
32        while(i < m && j < n) {
33            if(left[i] <= right[j]) {
34                nums[k] = left[i];
35                i++;
36            } else {
37                nums[k] = right[j];
38                j++;
39            }
40            k++;
41        }
42        while(i < m) {
43            nums[k] = left[i];
44            i++;
45            k++;
46        }
47        while(j < n) {
48            nums[k] = right[j];
49            j++;
50            k++;
51        }
52    }
53}