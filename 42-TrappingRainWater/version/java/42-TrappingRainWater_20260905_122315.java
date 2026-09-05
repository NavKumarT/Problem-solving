// Last updated: 9/5/2026, 12:23:15 PM
1class Solution {
2    public int trap(int[] height) {
3        int n = height.length;
4        int[] rightMax = new int[n];
5        
6        rightMax[n-1] = height[n-1];
7        int leftMax = height[0];
8        for(int i = n-2; i >= 0; i--){
9            rightMax[i] = Math.max(rightMax[i+1], height[i]);
10        }
11        int count = 0;
12        for(int i = 0; i < n; i++){
13            leftMax = Math.max(leftMax, height[i]);
14            count += Math.min(leftMax, rightMax[i]) - height[i];
15        }
16        return count;
17    }
18}