// Last updated: 8/29/2025, 9:48:47 PM
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), i = 0, curr = 0, ans = 0;
        if(n == 0)
            return curr;
        backtracking(nums, n, i, curr, ans);
        return ans;
    }

    void backtracking(vector<int> &nums, int n, int index, int curr, int &ans){
        if(index >= n){
            ans += curr;
            return;
        }
        int temp = curr;
        curr = curr ^ nums[index];
        index++;
        backtracking(nums, n, index, curr, ans);
        backtracking(nums, n, index, temp, ans);
    }
};