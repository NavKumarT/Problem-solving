// Last updated: 3/1/2026, 9:42:34 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0, high = nums.size()-1;
5        while(low <= high){
6            int mid = low + (high-low)/2;
7            if(nums[mid] == target)
8                return mid;
9            else if(nums[mid] > target)
10                high--;
11            else 
12                low++;
13        } 
14        return -1;
15    }
16};