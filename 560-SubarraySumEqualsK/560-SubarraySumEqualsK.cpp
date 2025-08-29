// Last updated: 8/29/2025, 9:50:30 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum = 0;
        unordered_map<int, int> s;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            psum += nums[i];
            if(psum == k)
                count++;
            if(s.find(psum-k) != s.end())
                count += s[psum-k];
            s[psum]++;
        }
        return count;
    }
};