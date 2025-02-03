class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // lets use dijkstra's algorithm to find the maximum probability path 
        vector<double> dist(n, INT_MIN);
        vector<vector<pair<double, int>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            adj[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }   

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;
        priority_queue<pair<double, int>> pq;

        pq.push(make_pair(1, start_node));
        dist[start_node] = 1;

        while(pq.empty() == false){
            pair<double, int> node = pq.top();
            pq.pop();

            for(pair<double, int> n : adj[node.second]){
                if(dist[node.second] * n.first > dist[n.second]){
                    dist[n.second] = dist[node.second] * n.first;
                    pq.push(make_pair(dist[n.second], n.second));
                }
            }
        }
        if(dist[end_node] == INT_MIN)
            return 0;
        return dist[end_node];
    }
};