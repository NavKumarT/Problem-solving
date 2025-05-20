// Last updated: 5/20/2025, 12:54:02 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};