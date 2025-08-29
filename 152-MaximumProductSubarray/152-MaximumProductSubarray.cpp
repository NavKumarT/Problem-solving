// Last updated: 8/29/2025, 9:51:39 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = 1;
        int ans = INT_MIN;
        int minProd = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                swap(maxProd, minProd);
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(minProd * nums[i], nums[i]);
            ans = max(maxProd, ans);
        }
        return ans;
    }
};