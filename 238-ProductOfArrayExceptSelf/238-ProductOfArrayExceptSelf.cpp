// Last updated: 8/29/2025, 9:51:11 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size());
        vector<int> suffixProduct(nums.size());
        prefixProduct[0] = 1;
        suffixProduct[nums.size()-1] = 1;
        for(int i = 1; i < nums.size(); i++){
            prefixProduct[i] = prefixProduct[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; i--){
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            ans.push_back(prefixProduct[i] * suffixProduct[i]);
        return ans;
    }
};