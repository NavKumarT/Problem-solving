// Last updated: 8/29/2025, 9:52:23 PM
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int largest = nums[n-1];
        int profit = 0;
        for(int i = n-2; i >= 0; i--){
            int temp = largest - nums[i];
            profit = max(temp, profit);
            largest = max(nums[i], largest);
        }
        return profit;
    }
};