// Last updated: 9/2/2026, 9:48:55 AM
1class Solution {
2    public boolean uniformArray(int[] nums1) {
3        int even = 0, odd=  0;
4        for(int num : nums1){
5            if(num % 2 == 0)
6                even++;
7            else 
8                odd++;
9        }
10        return true;
11        // return odd == 0 || even == 0 ? true : odd >= even;
12    }
13}