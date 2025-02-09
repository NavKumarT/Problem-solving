class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        long long n =nums.size();
        for(int i = 0; i < n; i++){
            mp[i-nums[i]]++;
        }
        long long  goodPairs = 0;
        for(auto it : mp){
            if(it.second > 1){
                goodPairs += (it.second * (it.second - 1)) / 2;
            }
        }
        long long totalPairs = (n * (n-1)) / 2;
        return totalPairs - goodPairs;
    }
};