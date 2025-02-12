class Solution {
public:
    int maximumSum(vector<int>& nums) {
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