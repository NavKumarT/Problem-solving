// Last updated: 5/20/2025, 3:46:58 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                if((mid == 0) || (nums[mid] != nums[mid-1])){
                    first = mid;
                    break;
                } else 
                    high = mid-1;
            } else if(nums[mid] > target)
                high = mid-1;
            else 
                low = mid+1;
        }
        low = 0, high = nums.size()-1;
         while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                if((mid == nums.size()-1) || (nums[mid] != nums[mid+1])){
                    last = mid;
                    break;
                }
                else 
                    low = mid+1;
            } else if(nums[mid] > target)
                high = mid-1;
            else 
                low = mid+1;
        }
        return {first, last};
    }
};