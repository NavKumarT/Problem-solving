// Last updated: 8/29/2025, 9:49:20 PM
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second >= 2){
                ans += 8 * ((it.second * (it.second - 1))/2);
            }
        }
        return ans;
    }
};