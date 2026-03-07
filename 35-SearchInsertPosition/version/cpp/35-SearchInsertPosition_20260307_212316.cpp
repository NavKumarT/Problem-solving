// Last updated: 3/7/2026, 9:23:16 PM
1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int low = 0, ceil = -1, high = nums.size()-1;
5        while(low <= high){
6            int mid = low + (high-low)/2;
7            if(nums[mid] == target){
8                return mid;
9            } else if(nums[mid] < target){
10                ceil = mid;
11                low = mid+1;
12            } else {
13                high = mid-1;
14            }
15        }
16        return ceil+1;
17    }
18};