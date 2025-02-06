class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int product = nums[i] * nums[j];
                mp[product]++;
                // mp[product].push_back(j);
            }
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second >= 2){
                ans += 8 * ((it.second * (it.second - 1))/2);
                // cout << it.first << " " << it.second.size() << " " << pow(2, (it.second.size()/2)+1) << endl;
            }
        }
        return ans;
    }
};