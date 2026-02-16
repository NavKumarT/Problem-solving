// Last updated: 2/16/2026, 1:17:44 PM
1class Solution {
2public:
3    int totalHammingDistance(vector<int>& nums) {
4        int count = 0;
5        int ones = 0, zeroes = 0;
6        int n = 0;
7        while(count < 32){
8            for(int i = 0; i < nums.size(); i++){
9                if(nums[i] & 1)
10                    ones += 1;
11                else 
12                    zeroes += 1;
13                nums[i] = nums[i] >> 1;
14            }
15            n += ones*zeroes;
16            ones = 0;
17            zeroes = 0;
18            count++;
19        }
20        return n;
21    }
22};