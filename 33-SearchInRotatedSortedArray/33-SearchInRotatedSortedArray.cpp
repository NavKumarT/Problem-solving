// Last updated: 8/29/2025, 9:53:10 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + high >> 1;
            if(nums[mid] == target)
                return mid;
            else {
                if(nums[mid] >= nums[low]){
                    if(nums[low] <= target && nums[mid] >= target)
                        high = mid-1;
                    else 
                        low = mid+1;
                } else {
                    if(nums[high] >= target && nums[mid] <= target)
                        low = mid+1;
                    else 
                        high = mid-1;
                }
            }
        }
        return -1;
    }
};