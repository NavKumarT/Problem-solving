// Last updated: 8/29/2025, 9:50:24 PM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int count = 0;
        int repeatedCount = 0;
        for(int i = 0; i < n; i++){
            count += nums[i];
        }
        unordered_set<int> s;
        for(int x : nums){
            if(s.find(x) != s.end()){
                repeatedCount = x;
                break;
            } else {
                s.insert(x);
            }
        }
        vector<int> ans;
        ans.push_back(repeatedCount);
        ans.push_back(repeatedCount + sum - count);
        return ans;
    }
};