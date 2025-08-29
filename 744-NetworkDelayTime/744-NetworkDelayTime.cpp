// Last updated: 8/29/2025, 9:50:12 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {weight, destination}
        vector<int> distance(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(int i = 0; i < times.size(); i++){
            graph[times[i][0]-1].push_back(make_pair(times[i][2], times[i][1]-1));
        }
        distance[k-1] = 0;
        pq.push(make_pair(0, k-1));
        while(pq.empty() == false){
            pair<int, int> p = pq.top();
            pq.pop();
            int weight = p.first;
            int node = p.second;
            if(weight > distance[node])
                continue;
            for (auto [w, nei] : graph[node]) {
    if (distance[nei] > weight + w) {
        distance[nei] = weight + w;
        pq.push({distance[nei], nei});
    }
}
        }
        int maxDelay = distance[0];
        for(int delay : distance)
            maxDelay = max(delay, maxDelay);
        return maxDelay == INT_MAX ? -1 : maxDelay;
    }
};