// Last updated: 2/19/2026, 11:36:08 AM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int low = 0, high = numbers.size()-1;
5        while(low < high){
6            int currSum = numbers[low] + numbers[high];
7            if(currSum == target)
8                return {low+1, high+1};
9            else if(currSum > target){
10                high--;
11            } else {
12                low++;
13            }
14        }
15        return {-1, -1};
16    }
17};