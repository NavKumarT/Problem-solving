// Last updated: 7/30/2026, 8:19:27 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        if(nums.size() == 0)
5            return 0;
6        unordered_set<int> s;
7        int ans = 1, count = 1;
8        for(int num : nums)
9            s.insert(num);
10        for(auto it : s){
11            if(s.find(it-1) == s.end()){
12                count = 1;
13                while(s.find(it+count) != s.end())
14                    count++;
15            }
16            ans = max(ans,count);
17        }
18        return ans;
19    }
20};