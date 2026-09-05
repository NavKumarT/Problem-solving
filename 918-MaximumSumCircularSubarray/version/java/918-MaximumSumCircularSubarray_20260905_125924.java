// Last updated: 9/5/2026, 12:59:24 PM
1class Solution {
2    public int maxSubarraySumCircular(int[] nums) {
3        int sum = nums[0];
4        int curr = nums[0], max = curr;
5        nums[0] = -nums[0];
6        for(int i = 1 ; i < nums.length; i++) {
7            int num = nums[i];
8            sum += num;
9            curr = Math.max(curr+num, num);
10            max = Math.max(curr, max);
11            nums[i] = -nums[i];
12        }
13        int maxNegative = kadane(nums);
14        if(max < 0)
15            return max;
16        return max > sum+maxNegative ? max : (sum + maxNegative);
17    }
18
19    private int kadane(int[] nums) {
20        int curr = 0, max = curr;
21        for(int num : nums) {
22            curr = Math.max(curr+num, num);
23            max = Math.max(curr, max);
24        }
25        return max;
26    }
27}