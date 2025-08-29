// Last updated: 8/29/2025, 9:53:15 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int i = 0;
        int count = 0;
        while(i < nums.size()){
            if(nums[i] == val){
                i++;
                count++;
            } else {
                nums[start] = nums[i];
                start++;
                i++;
            }
        }
        return nums.size()-count;
    }
};