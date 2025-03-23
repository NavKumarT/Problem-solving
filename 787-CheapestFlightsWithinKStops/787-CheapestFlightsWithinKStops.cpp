// Last updated: 3/23/2025, 1:34:40 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(vector<int> flight : flights){
            adj[flight[0]].push_back(make_pair(flight[2], flight[1]));
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0,src,0); // cost, node, stops 
        while(pq.empty() == false){
            auto [stops, node, currCost] = pq.top(); pq.pop();
            // cout << currCost << " " << node << " " << stops << endl;
            // if((stops > k && node != dst) || currCost > dist[node])
            //     continue;
            if(stops > k)
                break;
            for(pair<int, int> p : adj[node]){
                if(currCost + p.first < dist[p.second]){
                    dist[p.second] = currCost + p.first;
                    pq.emplace(stops+1, p.second, currCost+p.first);
                }
            }
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};