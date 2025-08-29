// Last updated: 8/29/2025, 9:47:56 PM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        if(nums.size() <= 1)
            return -1;
        int num = nums[0], count = 1;
        mp[num]++;
        for(int i = 1; i < nums.size(); i++){
            mp[nums[i]]++;
            if(nums[i] == num){
                count++;
            } else {
                count--;
                if(count == 0){
                    num = nums[i];
                    count = 1;
                }
            }
        }
        int occurence = mp[num];
        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num){
                count++;
            }
            if((count * 2  > i +1) && ((occurence - count)*2 > nums.size()-1-i))
                return i;
        }

        return -1;
    }
};