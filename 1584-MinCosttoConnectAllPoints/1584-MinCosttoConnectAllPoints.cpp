class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                if(i != j){
                    int cost = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                    adj[i].push_back(make_pair(cost, j));
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push(make_pair(0, 0));
        vector<bool> visited(points.size(), false);
        int ans = 0;
        while(pq.empty() == false){
            pair<int, int> minEdge = pq.top();
            pq.pop();
            if(visited[minEdge.second])
                continue;
            ans += minEdge.first;
            visited[minEdge.second] = true;            
            for(auto neighbour : adj[minEdge.second]){
                pq.push(neighbour);
            }
        }
        return ans;
    }
};