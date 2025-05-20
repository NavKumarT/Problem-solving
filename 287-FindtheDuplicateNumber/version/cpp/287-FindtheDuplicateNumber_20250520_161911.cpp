// Last updated: 5/20/2025, 4:19:11 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i <nums.size(); i++){
            int indexToSearch = abs(nums[i])-1;
            if(nums[indexToSearch] < 0)
                return indexToSearch+1;
            else 
                nums[indexToSearch] *= -1;
        }
        return 0;
    }
};