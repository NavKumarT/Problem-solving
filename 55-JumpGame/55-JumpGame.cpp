// Last updated: 8/29/2025, 9:52:59 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            if(i >= start && i<= end){
                start = min(start , i);
                end = max(end, i + nums[i]);
            }
        }
        return end >= n-1;

        // return func(nums, n);
    }

    bool func(vector<int> nums, int n){
        // vector<bool> memo(n, false);
        // memo[0] = true;
        // for(int i = 0; i < n; i++){
        //     if(memo[i] == false)
        //         continue;
        //     for(int j = i+1; j < n && j <= i+nums[i]; j++)
        //         memo[j] = memo[i] && true;
        //     if(memo[n-1] == true)
        //         return true;
        // }
        // return memo[n-1] == true;

        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            if(i >= start && i<= end){
                start = min(start , i);
                end = max(end, i + nums[i]);
            }
        }
        return end >= n-1;
    }
};