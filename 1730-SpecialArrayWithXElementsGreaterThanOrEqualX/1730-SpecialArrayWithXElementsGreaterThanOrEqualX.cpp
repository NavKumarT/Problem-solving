// Last updated: 8/29/2025, 9:49:00 PM
class Solution {
public:
    int specialArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> frequency(n+1, 0);
       for(int i = 0; i < n; i++){
           frequency[min(n, nums[i])]++;
       }
       int psum = 0;
       for(int i = n; i>= 1; i--){
        psum += frequency[i];
        if(psum == i)
            return psum;
       }
       return -1;
    }
};