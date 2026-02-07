// Last updated: 2/7/2026, 1:11:58 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        for(int i = 0; i < nums.size(); i++){
5            int num = abs(nums[i]);
6            if(nums[num-1] < 0)
7                return num;
8            nums[num-1] = -1 * nums[num-1];
9        }
10        return -1;
11    }
12};