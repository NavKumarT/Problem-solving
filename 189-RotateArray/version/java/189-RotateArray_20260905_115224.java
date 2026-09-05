// Last updated: 9/5/2026, 11:52:24 AM
1class Solution {
2    public void rotate(int[] nums, int k) {
3        // reverse the whole array 
4        // reverse the first k
5        // reverse the rest
6        int n = nums.length;
7        k =  k % n;
8        reverse(nums, 0, n-1);
9        reverse(nums, 0, k-1);
10        reverse(nums, k, n-1);
11    }
12    
13    private void reverse(int[] nums, int first, int last) {
14        while(first < last){
15            int temp = nums[first];
16            nums[first] = nums[last];
17            nums[last] = temp;
18            first++;
19            last--;
20        }
21    }
22    
23}