class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int pos = -1, neg = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] > 0){
                if(mid == 0 || nums[mid-1] <= 0){
                    pos = mid;
                    break;
                } else {
                    high = mid-1;
                }
            } else {
                low = mid + 1;
            }
        }
        low = 0; high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < 0){
                if(mid == nums.size()-1 || nums[mid+1] >= 0){
                    neg = mid;
                    break;
                } else {
                    low = mid+1;
                }
            } else {
                high = mid - 1;
            }
        }
        low = 0; high = nums.size()-1; 
        int fzero = -1, szero = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == 0){
                if(mid == nums.size()-1 || nums[mid+1] > 0){
                    szero = mid;
                    break;
                } else {
                    low = mid+1;
                }
            } else if(nums[mid] > 0){
                high = mid - 1;
            } else {
                low = mid +1;
            }
        }
        low = 0; high = nums.size()-1; 
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == 0){
                if(mid == 0 || nums[mid-1] < 0){
                    fzero = mid;
                    break;
                } else {
                    high = mid-1;
                }
            } else {
                low = mid + 1;
            }
        }
        int zeroes = (szero == -1 ) ? 0 : szero-fzero+1;
        if(pos == -1 || neg == -1)
            return nums.size()-zeroes;
        
        else 
            return neg+1 > nums.size()-pos ? neg+1 : nums.size()-pos;
        
    }
};