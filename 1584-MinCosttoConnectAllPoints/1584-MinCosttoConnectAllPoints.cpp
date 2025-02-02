class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                // cout << "i : " << i  << " ";
                if(i != j){
                    int cost = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                    adj[i].push_back(make_pair(cost, j));
                    // cout << "j, cost: " << j << ", " << cost;
                }
                // cout << endl;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push(make_pair(0, 0));
        vector<bool> visited(points.size(), false);
        // visited[0] = true;
        int ans = 0;
        while(pq.empty() == false){
            pair<int, int> minEdge = pq.top();
            pq.pop();
            if(visited[minEdge.second])
                continue;
            ans += minEdge.first;
            visited[minEdge.second] = true;
            // cout << minEdge.first << " " << minEdge.second <<endl;
            
            for(auto neighbour : adj[minEdge.second]){
                // if(visited[neighbour.second] == false){
                //     visited[neighbour.second] = true;
                //     cout << neighbour.first << " " << neighbour.second << endl;
                //     for(auto neighbour1 : adj[neighbour.second]){
                        // visited[neighbour.second] = true;
                        pq.push(neighbour);
                    // }
                    // pq.push(neighbour);
                
            }
        }
        return ans;
    }
};