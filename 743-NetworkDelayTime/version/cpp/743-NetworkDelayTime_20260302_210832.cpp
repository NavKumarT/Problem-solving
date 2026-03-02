// Last updated: 3/2/2026, 9:08:32 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<int> dist(n+1, INT_MAX);
5        dist[k] = 0;
6        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
7        pq.push({0, k});
8        vector<vector<pair<int, int>>> adj(n+1);
9        for(const vector<int> &time : times){
10            int u = time[0], v = time[1], weight = time[2];
11            adj[u].push_back({v, weight});
12        }
13        while(!pq.empty()){
14            auto [distance, vertex] = pq.top();
15            pq.pop();
16            if(distance > dist[vertex])
17                continue;
18            for(const pair<int, int> p : adj[vertex]){
19                if(distance + p.second < dist[p.first]){
20                    dist[p.first] = distance + p.second;
21                    pq.push({dist[p.first], p.first});
22                }
23            }
24        }
25        int nn = INT_MIN;
26        for(int i = 1; i <= n; i++){
27            nn = max(nn, dist[i]);
28        }
29        return nn == INT_MAX ? -1 : nn;
30
31        
32    }
33};