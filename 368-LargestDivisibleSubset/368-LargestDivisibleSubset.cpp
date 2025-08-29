// Last updated: 8/29/2025, 9:50:56 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxIndex = 0, maxSize = 0;
        vector<vector<int>> memo(n, vector<int>(0));
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j] == 0 && memo[j].size() > temp.size())
                    temp = memo[j];
            }
            temp.push_back(nums[i]);
            memo[i] = temp;
            if(temp.size() > maxSize){
                maxIndex = i;
                maxSize = temp.size();
            }
        }
        return memo[maxIndex];
    }
};