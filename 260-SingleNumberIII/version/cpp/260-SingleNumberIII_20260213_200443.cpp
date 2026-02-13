// Last updated: 2/13/2026, 8:04:43 PM
1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        long long int x = 0;
5        for(int num : nums)
6            x = x ^ num;
7        long long int sb = x &(~(x-1));
8        int res1 = 0, res2 = 0;
9        for(int num : nums){
10            if(sb & num)
11                res1 ^= num;
12            else    
13                res2 ^= num;
14        }
15        return {res1, res2};
16    }
17};