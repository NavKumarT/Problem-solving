// Last updated: 2/18/2026, 9:20:08 AM
1class Solution {
2public:
3    vector<int> sortArrayByParity(vector<int>& nums) {
4        int start = 0, end = nums.size()-1;
5        while(start < end){
6            while(start < end && nums[start] % 2 == 0){
7                start++;
8            }
9            while(start < end && nums[end] % 2 != 0){
10                end--;
11            }
12            swap(nums[start++], nums[end--]);
13        }
14        return nums;
15    }
16};