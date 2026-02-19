// Last updated: 2/19/2026, 1:40:24 PM
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int low = 0, high = height.size()-1;
5        int n = INT_MIN;
6        while(low < high){
7            int water = min(height[low], height[high]) * (high-low);
8            n = max(n, water);
9            if(height[low] < height[high])
10                low++;
11            else 
12                high--;
13        }
14        return n;
15    }
16};