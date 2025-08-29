// Last updated: 8/29/2025, 9:50:34 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high  = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mid == 0 && (nums.size() == 1 || nums[mid] != nums[mid+1]) )
                return nums[mid];
            if(mid == nums.size()-1 && (nums.size() == 1 || nums[mid] != nums[mid-1]))
                return nums[mid];
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid % 2 == 0 && mid > 0){
                if(nums[mid] == nums[mid-1]){
                    high = mid-1;
                    continue;
                } else {
                    low = mid+1;
                    continue;
                }
            }
            if(mid % 2 != 0 && mid > 0){
                if(nums[mid] == nums[mid-1]){
                    low = mid+1;
                    continue;
                } else {
                    high = mid-1;
                    continue;
                }
            }
        }
        return -1;
    }
};