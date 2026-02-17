// Last updated: 2/17/2026, 10:34:46 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n = 0;
5        for(int j = 0; j < 32; j++){
6            int count = 0;
7            for(int i = 0 ; i < nums.size(); i++){
8                if(nums[i] & (1 << j))
9                    count++;
10            }
11            if(count % 3)
12                n = n | (1 << j);
13        }
14        return n;
15    }
16};