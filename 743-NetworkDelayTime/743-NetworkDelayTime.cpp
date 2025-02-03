class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);

        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back(make_pair(times[i][2], times[i][1]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k));
        dist[k] = 0;

        while(pq.empty() == false){
            pair<int, int> node = pq.top();
            pq.pop();

            for(pair<int,int> n : adj[node.second]){
                if(dist[node.second] + n.first < dist[n.second]){
                    dist[n.second] = dist[node.second] + n.first;
                    pq.push(make_pair(dist[n.second], n.second));
                }
            }
        } 

        int ans = dist[1];
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};