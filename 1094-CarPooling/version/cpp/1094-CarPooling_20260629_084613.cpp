// Last updated: 6/29/2026, 8:46:13 AM
1class Solution {
2public:
3    bool carPooling(vector<vector<int>>& trips, int capacity) {
4        vector<vector<int>> events;
5        for(vector<int> &trip : trips){
6            events.push_back({trip[1], trip[0]});
7            events.push_back({trip[2], trip[0] * -1});
8        }
9        sort(events.begin(), events.end(), [](vector<int> &event1, vector<int> &event2){
10            if(event1[0] == event2[0])
11                return event1[1] < event2[1];
12            return event1[0] < event2[0];
13        });
14        int currentCapacity = 0;
15        for(vector<int> &event : events){
16            currentCapacity += event[1];
17            if(currentCapacity > capacity)
18                return false;
19        }
20        return true;
21    }
22};