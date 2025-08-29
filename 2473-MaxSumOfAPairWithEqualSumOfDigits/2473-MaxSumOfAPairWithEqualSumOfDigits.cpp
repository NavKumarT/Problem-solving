// Last updated: 8/29/2025, 9:48:16 PM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // time: O(N) , extract max takes constant time, time is spent only on building the map 
        unordered_map<int, priority_queue<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            int number = nums[i];
            int sum = 0;
            while(number > 0){
                sum += number % 10;
                number = number /10;
            }
            mp[sum].push(nums[i]);
        }
        int ans = -1;
        // always we extract max only twice so it doesnt affect the asymptotic time complexity 
        for(auto it : mp){
            if(it.second.size() > 1){
                int a = it.second.top(); it.second.pop();
                int b = it.second.top(); it.second.pop();
                ans = max(ans, a + b);
            }
        }
        return ans;
    }
};