// Last updated: 8/29/2025, 9:52:45 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;
            } else {
                if(nums[mid] == nums[low] && nums[low] == nums[high]){
                    low++;
                    high--;
                    continue;
                }
                if(nums[mid] >= nums[low]){
                    if(nums[mid] > target && target >= nums[low])
                        high = mid-1;
                    else 
                        low = mid+1;
                } else {
                    if(nums[high] >= target && target > nums[mid])
                        low = mid+1;
                    else 
                        high = mid-1;
                }
            }
        }
        return false;
    }
};