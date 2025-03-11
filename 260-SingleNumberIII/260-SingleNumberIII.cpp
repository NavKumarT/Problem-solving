class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(int i : nums)
            x ^= i;
        long long sb = x & (~(x-1));
        int res1 = 0, res2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & sb) == 0)
                res1 = res1 ^ nums[i];
            else
                res2 = res2 ^ nums[i];
        }
        return {res1, res2};
    }
};