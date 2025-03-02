class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 2)
            return {nums[0]};
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1){
                count1++;
            } else if(nums[i] == candidate2){
                count2++;
            } else if(count1 == 0){
                count1 = 1;
                candidate1 = nums[i];
            }else if(count2 == 0){
                count2 = 1;
                candidate2 = nums[i];
            }else {
                count1--;
                count2--;
            }
        } 
        cout << candidate1 << " " << candidate2 << endl;
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for(int x : nums){
            if(x == candidate1)
                count1++;
            if(x == candidate2) 
                count2++;
        }
        if(count1 > nums.size()/3)
            ans.push_back(candidate1);
        if(count2 > nums.size()/3)
            ans.push_back(candidate2);
        return ans;
    }
};