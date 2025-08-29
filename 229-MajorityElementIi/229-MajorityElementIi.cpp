// Last updated: 8/29/2025, 9:51:17 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN, count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1)
                count1++;
            else if(nums[i] == candidate2)
                count2++;
            else if(count1 == 0){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2 == 0){
                count2 = 1;
                candidate2 = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i : nums)
            if(i == candidate1)
                count1++;
            else if(i == candidate2)
                count2++;
        vector<int> res;
        if(count1 > nums.size()/3)
            res.push_back(candidate1);
        if(count2 > nums.size()/3)
            res.push_back(candidate2);
        return res;
    }
};