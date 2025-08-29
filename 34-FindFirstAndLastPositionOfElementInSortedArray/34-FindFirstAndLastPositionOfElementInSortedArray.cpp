// Last updated: 8/29/2025, 9:53:09 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int first = -1, last = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid] != nums[mid-1]){
                    first = mid;
                    break;
                } else {
                    end = mid-1;
                }
            } else if (nums[mid] < target){
                start = mid+1;
            } else {
                end = mid -1;
            }
        }
        if(first == -1)
            return {first, last};
        start = first;
        end = nums.size()-1;
         while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                if(mid == nums.size()-1 || nums[mid] != nums[mid+1]){
                    last = mid;
                    break;
                } else {
                    start = mid+1;
                }
            } else if (nums[mid] < target){
                start = mid+1;
            } else {
                end = mid -1;
            }
        }
        return {first, last};

    }
};