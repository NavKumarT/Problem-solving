// Last updated: 8/29/2025, 9:51:05 PM
class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        int psum = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            ans.push_back(psum + nums[i]);
            psum += temp;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return ans[right];
        else 
            return ans[right] - ans[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */