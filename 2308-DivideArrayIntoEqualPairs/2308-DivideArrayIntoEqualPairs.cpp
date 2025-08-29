// Last updated: 8/29/2025, 9:48:25 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> s;
        for(int i : nums)
            s[i]++;
        int count = 0;
        for(auto it : s){
            if(it.second % 2 != 0)
                return false;
            else {
                count += it.second/2;
            }
        }
        return count  == (n/2);
    }
};