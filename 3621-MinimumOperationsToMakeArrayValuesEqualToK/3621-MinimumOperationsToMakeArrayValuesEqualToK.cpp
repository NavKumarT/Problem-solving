// Last updated: 8/29/2025, 9:47:31 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_set<int> s;
        bool kPresent = false;
        for(int num : nums){
            if(num >= k){
                count++;
                s.insert(num);
            }
            if(num == k)
                kPresent = true;
        }
        if(count < nums.size())
            return -1;
        return kPresent ? s.size()-1 : s.size();

    }
};