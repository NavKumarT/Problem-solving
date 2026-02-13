// Last updated: 2/13/2026, 9:22:51 PM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int prev = 0;
5        for(int i = 1; i < nums.size(); i++){
6            if(nums[i] != nums[i-1]){
7                prev++;
8                nums[prev] = nums[i];
9            }
10        }
11        return prev+1;
12    }
13};