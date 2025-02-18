class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentRes;
        func(currentRes, result, 0, nums);
        return result;
    }


           
    void func(vector<int> &currentRes, vector<vector<int>> &result, int n, vector<int> &nums){
        if(n >= nums.size()){
            result.push_back(currentRes);
            return;
        }
   
        currentRes.push_back(nums[n]);
        func(currentRes, result, n+1, nums);
        currentRes.pop_back();
        func(currentRes, result, n+1, nums);
        
        return;
    }

};