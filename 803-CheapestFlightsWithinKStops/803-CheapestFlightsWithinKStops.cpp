// Last updated: 8/29/2025, 9:50:04 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<int> temp(n, INT_MAX);
        dist[src] = 0;
        temp[src] = 0;
        for(int i = 0; i < k+1; i++){
            for(vector<int> flight : flights){
                if(temp[flight[0]] != INT_MAX && temp[flight[0]] + flight[2] < dist[flight[1]]){
                    dist[flight[1]] = temp[flight[0]] + flight[2]; 
                }
            }
            temp = dist;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};