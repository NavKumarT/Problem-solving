// Last updated: 2/19/2026, 12:34:21 PM
1class Solution {
2public:
3    int threeSumClosest(vector<int>& nums, int target) {
4        int n = -1, closest = INT_MAX;
5        sort(nums.begin(), nums.end());
6        for(int i = 0; i < nums.size()-2; i++){
7            if(i > 0 && nums[i] == nums[i-1])
8                continue;
9            int currSum = nums[i];
10            int high = nums.size()-1, low = i+1;
11            while(low < high){
12                if( abs(target - (currSum + nums[low] + nums[high])) < closest){
13                    closest =  abs(target - (currSum + nums[low] + nums[high]));
14                    n = currSum + nums[low] + nums[high];
15                }
16                if(currSum + nums[low] + nums[high] == target){
17                    return currSum + nums[low] + nums[high];
18                } else if(currSum + nums[low] + nums[high] > target){
19                    high--;
20                } else {
21                    low++;
22                }
23            }
24        }
25        return n;
26    }
27};