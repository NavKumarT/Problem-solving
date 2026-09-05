// Last updated: 9/5/2026, 12:21:54 PM
1class Solution {
2    public int trap(int[] height) {
3        int n = height.length;
4        int[] leftMax = new int[n];
5        int[] rightMax = new int[n];
6        leftMax[0] = height[0];
7        rightMax[n-1] = height[n-1];
8        for(int i = 1; i < n; i++){
9            leftMax[i] = Math.max(leftMax[i-1], height[i]);
10        }
11        for(int i = n-2; i >= 0; i--){
12            rightMax[i] = Math.max(rightMax[i+1], height[i]);
13        }
14        int count = 0;
15        for(int i = 0; i < n; i++){
16            count += Math.min(leftMax[i], rightMax[i]) - height[i];
17        }
18        return count;
19    }
20}