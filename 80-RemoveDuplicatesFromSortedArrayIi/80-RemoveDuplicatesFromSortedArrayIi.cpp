// Last updated: 8/29/2025, 9:52:46 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if((nums[i] != nums[j-1]) || (j > 1 && nums[i] == nums[j-1] && nums[j-1] != nums[j-2]) || j <= 1){
                nums[j] = nums[i];
                j++;
                count++;
            }
        }
        return count;
    }
};