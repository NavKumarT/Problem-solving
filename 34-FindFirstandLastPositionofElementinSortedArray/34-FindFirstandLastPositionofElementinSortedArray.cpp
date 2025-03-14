class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, second = -1;
        int low = 0, high = nums.size()-1;
        int n = nums.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid] != nums[mid-1]){
                    first = mid;
                    break;
                } else {
                    high = mid-1;
                }
            } else if(nums[mid] > target){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        low = 0; high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                if(mid == n-1 || nums[mid] != nums[mid+1]){
                    second = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            } else if(nums[mid] > target){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return {first, second};
    }
};