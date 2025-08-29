// Last updated: 8/29/2025, 9:49:01 PM
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // buld adjacency matrix based on manhattan dist 
        vector<vector<int>> graph(points.size(), vector<int>(points.size()));
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                graph[i][j] = manhattan(points[i], points[j]);
            }
        }
        vector<int> dist(points.size(), INT_MAX);
        vector<bool> visited(points.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // map dist and cell
        pq.push(make_pair(0, 0));
        dist[0] = 0;
        int ans = 0;
        while(pq.empty() == false){
            pair<int, int> p = pq.top(); pq.pop();
            int cell = p.second;
            int weight = p.first;
            if(visited[cell])
                continue;
            ans += weight;
            visited[cell] = true;
            for(int i = 0; i < points.size(); i++){
                if(visited[i] == false && graph[cell][i] < dist[i]){
                    dist[i] = graph[cell][i];
                    pq.push(make_pair(graph[cell][i], i));
                }
            }
        }
        // pick up the first element and start min heap based bfs
        return ans;
    }


    int manhattan(vector<int> a, vector<int> b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
};