// Last updated: 8/29/2025, 9:51:21 PM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, curr = 0;
        int size = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            end = i;
            while(curr >= target){
                size = min(size, end-start+1);
                curr -= nums[start];
                start++;
            }
        }
        return size == INT_MAX ? 0 : size;
    }
};