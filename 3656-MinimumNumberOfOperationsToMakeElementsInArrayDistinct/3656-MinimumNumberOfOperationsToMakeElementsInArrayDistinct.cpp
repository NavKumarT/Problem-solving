// Last updated: 8/29/2025, 9:47:28 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        unordered_set<int> s;
        for(int i = n-1; i >= 0; i--){
            if(s.find(nums[i]) != s.end()){
                break;
            }
            count++;
            s.insert(nums[i]);
        }
        int itemsToRemove = n - count;
        return itemsToRemove % 3 == 0 ? itemsToRemove / 3 : (itemsToRemove / 3) + 1;
    }
};