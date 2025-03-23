// Last updated: 3/23/2025, 3:02:06 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // use dijsktras algo for finding the distance of each node to every other node 

        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(make_pair(edge[2], edge[1]));
            adj[edge[1]].push_back(make_pair(edge[2], edge[0]));
        }

        int ans = INT_MAX, curr = -1;
        for(int i = 0; i < n; i++){
            dijkstra(i, adj, n, ans, curr, distanceThreshold);
            // cout << ans << " " << curr << endl;
        }
        return curr;
    }

    void dijkstra(int source, vector<vector<pair<int, int>>> &adj, int n, int &ans, int &curr, int distanceThreshold){
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, source);
        while(pq.empty() == false){
            auto [cost, node] = pq.top(); pq.pop();
            for(pair<int, int> p : adj[node]){
                if(cost + p.first < dist[p.second]){
                    dist[p.second] = cost + p.first;
                    pq.push(make_pair(cost+p.first, p.second));
                }
            }
        }
        int temp = 0;
        for(int distance : dist){
            // cout << distance << " ";
            if(distance <= distanceThreshold){
                temp++;
            }
        }
        if(temp <= ans){
            ans = temp;
            curr = source;
        }
    }


};