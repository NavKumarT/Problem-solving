// Last updated: 2/17/2026, 6:39:51 PM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int start = -1;
5        for(int i = 0; i < nums.size(); i++){
6            int num = nums[i];
7            if(num != 0){
8                start++;
9                swap(nums[i], nums[start]);
10            }
11        }
12    }
13};