// Last updated: 8/29/2025, 9:51:33 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // rotate the first n-k elements 
        // rotate the last k elements 
        // rotate the entire array
        // all rotations are in-place 
        // Time: O(k) + (n-k) ~ O(n)
        // Space: No extra space 
        k = k % nums.size();
        rotateArray(nums, 0, nums.size()-k-1);
        rotateArray(nums, nums.size()-k, nums.size()-1);
        rotateArray(nums, 0, nums.size()-1);
    }

    void rotateArray(vector<int> &nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};