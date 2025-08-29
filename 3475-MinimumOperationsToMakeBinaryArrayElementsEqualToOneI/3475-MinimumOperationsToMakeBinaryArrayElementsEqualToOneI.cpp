// Last updated: 8/29/2025, 9:47:39 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans++;
                int j = i;
                int count = 0;
                while(j < nums.size() && count < 3){
                    count++;
                    nums[j] = nums[j] == 0 ? 1 : 0;
                    j++;
                }
                if(count < 3)
                    return -1;
            }
        }
        return ans;
    }
};