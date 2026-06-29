// Last updated: 6/29/2026, 9:00:06 AM
1class Solution {
2public:
3    bool carPooling(vector<vector<int>>& trips, int capacity) {
4        vector<long long> events(1001, 0);
5        for(vector<int> &trip : trips){
6            events[trip[1]] += trip[0];
7            events[trip[2]] -= trip[0];
8        }
9
10        int presum = 0;
11        for(int event : events){
12            presum += event;
13            if(presum > capacity)
14                return false;
15        }
16
17        return true;
18    }
19};