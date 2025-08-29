// Last updated: 8/29/2025, 9:48:28 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for(int num : nums)
            if(num < pivot)
                ans.push_back(num);
        for(int num : nums)
            if(num == pivot)
                ans.push_back(num);
        for(int num : nums)
            if(num > pivot)
                ans.push_back(num);
        return ans;
    }
};