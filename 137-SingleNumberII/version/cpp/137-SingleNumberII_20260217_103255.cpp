// Last updated: 2/17/2026, 10:32:55 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n = 0;
5        for(int j = 0; j < 32; j++){
6            int count = 0;
7            for(int i = 0 ; i < nums.size(); i++){
8                if(nums[i] & 1)
9                    count++;
10                nums[i] = nums[i] >> 1;
11            }
12            // set the bit based on n % 3
13            if(count % 3)
14                n = n | (1 << j);
15        }
16        return n;
17    }
18};