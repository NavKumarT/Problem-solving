// Last updated: 3/3/2026, 10:01:23 PM
1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4        // lets use dijkstra's algorithm to find the maximum probability path 
5        // we will be using max heap instead of the usual min heap 
6        // while relaxing the edges make sure to maximize and not minimize 
7        vector<double> dist(n, INT_MIN);
8        vector<vector<pair<double, int>>> adj(n);
9
10        for(int i = 0; i < edges.size(); i++){
11            adj[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
12            adj[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
13        }   
14
15        priority_queue<pair<double, int>> pq;
16
17        pq.push(make_pair(1, start_node));
18        dist[start_node] = 1;
19
20        while(pq.empty() == false){
21            pair<double, int> node = pq.top();
22            pq.pop();
23
24            for(pair<double, int> n : adj[node.second]){
25                if(dist[node.second] * n.first > dist[n.second]){
26                    dist[n.second] = dist[node.second] * n.first;
27                    pq.push(make_pair(dist[n.second], n.second));
28                }
29            }
30        }
31        if(dist[end_node] == INT_MIN)
32            return 0;
33        return dist[end_node];
34    }
35};