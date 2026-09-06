// Last updated: 9/6/2026, 10:59:51 AM
1import java.util.Arrays;
2
3class Solution {
4    public static void merge(int[] nums1, int m, int[] nums2, int n) {
5        int j = nums1.length-1;
6        while(m >= 1 && n >= 1) {
7            if(nums1[m-1] >= nums2[n-1]) {
8                nums1[j] = nums1[m-1];
9                m--;
10            } else {
11                nums1[j] = nums2[n-1];
12                n--;
13            }
14            j--;
15        }
16        while(m >= 1) {
17            nums1[j] = nums1[m-1];
18            j--;
19            m--;
20        }
21        while(n >= 1) {
22            nums1[j] = nums2[n-1];
23            j--;
24            n--;
25        }
26    }
27}