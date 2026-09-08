// Last updated: 9/8/2026, 12:05:51 PM
1class Solution {
2    public long zeroFilledSubarray(int[] nums) {
3        long count = 0;
4        long start = -1, end = -1;
5        
6        // [1, 2, 3, 0, 0]
7        for(int i = 0; i < nums.length; i++) { 
8            if(nums[i] == 0) {
9                if(start == -1) {
10                    start = end = i;
11                } else  {
12                    end = i;
13                }
14            } else {
15                if(start != -1) {
16                    long length = end-start+1;
17                    count += (length * (length+1)) / 2;
18                    start = end = -1;
19                }
20            }
21        }
22
23        if(start != -1) {
24            long length = end-start+1;
25            count += (length * (length+1)) / 2;
26        }
27        return count;
28    }
29}