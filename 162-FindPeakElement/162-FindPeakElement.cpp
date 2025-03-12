class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, n = nums.size();
        if(n == 1) return 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] < nums[mid+1])){
                low = mid+1;
            } else if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1])){
                return mid;
            } else {
                high = mid-1;
            }
        }
        return high >= 0 && high < n ? high : low;
    }
};