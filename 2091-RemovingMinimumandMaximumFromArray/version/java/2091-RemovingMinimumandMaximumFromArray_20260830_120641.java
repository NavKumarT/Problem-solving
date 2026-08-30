// Last updated: 8/30/2026, 12:06:41 PM
1class Solution {
2    public int minimumDeletions(int[] nums) {
3        if(nums.length == 1)
4            return 1;
5        Integer maxIndex = -1;
6        Integer minIndex = -1;
7        for(int i = 0; i < nums.length; i++){
8            minIndex = minIndex == -1 || nums[i] < nums[minIndex] ? i : minIndex;
9            maxIndex = maxIndex == -1 || nums[i] > nums[maxIndex] ? i : maxIndex;
10        }
11        int left = Math.min(minIndex, maxIndex);
12        int right = Math.max(minIndex, maxIndex);
13        
14        int a = left, b = nums.length-right-1, c = Math.abs(left - right)-1;
15
16        return nums.length-Math.max(a, Math.max(b, c));
17    }
18}