// Last updated: 2/19/2026, 12:06:02 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> n;
5        sort(nums.begin(), nums.end());
6        for(int i = 0; i < nums.size()-2; i++){
7            if(i > 0 && nums[i] == nums[i-1])
8                continue;
9            int currSum = nums[i];
10            int high = nums.size()-1, low = i+1;
11            while(low < high){
12                if(currSum + nums[low] + nums[high] == 0){
13                    n.push_back({nums[i], nums[low], nums[high]});
14                    low++;
15                    high--;
16                    while(low < high && nums[low-1] == nums[low]){
17                        low++;
18                    }
19                    while(low < high && nums[high] == nums[high+1]){
20                        high--;
21                    }
22                } else if(currSum + nums[low] + nums[high] > 0){
23                    high--;
24                } else {
25                    low++;
26                }
27            }
28        }
29        return n;
30    }
31};