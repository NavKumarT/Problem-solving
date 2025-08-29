// Last updated: 8/29/2025, 9:48:01 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>> graph(n);
        for(vector<int> edge : edges){
            sort(edge.begin(), edge.end());
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                visited[i] = true;
                if(bfs(visited, i, graph, count)){
                    count++;
                }
            }
        }
        return count;
    }
    bool bfs(vector<bool> &visited, int i, vector<vector<int>> &graph, int &count){
        queue<int> q;
        q.push(i);
        int edges = 0, nodes = 0;
        while(q.empty() == false){
            int  node = q.front(); q.pop();
            nodes++;
            for(int x : graph[node]){
                edges++;
                if(visited[x] == false){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        edges = edges / 2;
        return nodes == 1 ? true : edges == ((nodes) * (nodes-1) / 2);
    }
};