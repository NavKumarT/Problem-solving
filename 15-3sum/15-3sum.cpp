// Last updated: 8/29/2025, 9:53:24 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int i = 0; i < nums.size()-2; i++){
            int target = -1 * nums[i];
            int low = i+1, high = nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(low < high){
                int sum = nums[low] + nums[high];
                if(sum == target){
                    v.push_back({nums[i], nums[low], nums[high]});
                    low = low+1;
                    while(low < nums.size() && nums[low] == nums[low-1])
                        low++;
                } else if(sum < target){
                    low++;
                } else {
                    high--;
                }
            }
        }
        return v;
    }
};