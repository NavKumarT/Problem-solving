class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        if(nums.size() > 1 && nums[nums.size()-2] == nums[nums.size()-1] )
            return true;
        return false;
    }
    
};