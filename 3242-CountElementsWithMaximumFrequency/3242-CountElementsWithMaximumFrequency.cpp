// Last updated: 1/3/2026, 12:24:48 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maximumOccurence = -1, count = 0;
        for(int num : nums){
            mp[num]++;
            maximumOccurence = max(maximumOccurence, mp[num]);
        }
        for(auto it : mp){
            if(it.second == maximumOccurence)
                count += maximumOccurence;
        }
        return count;
    }
};