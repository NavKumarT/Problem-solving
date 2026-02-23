// Last updated: 2/24/2026, 12:15:53 AM
1class Solution {
2public:
3    int findCircleNum(vector<vector<int>>& isConnected) {
4        int n = isConnected.size();
5        vector<bool> visited(n, false);
6        int count = 0;
7        for(int i = 0; i < n; i++){
8            if(visited[i] == false){
9                count++;
10                bfs(i, visited, isConnected);
11            }
12        }
13        return count;
14    }
15
16    void bfs(int j, vector<bool> &visited, vector<vector<int>> &grid){
17        visited[j] = true;
18        queue<int> q;
19        q.push(j);
20        while(q.empty() == false){
21            int j = q.front();
22            q.pop();
23for(int i = 0; i < visited.size(); i++){
24            if(grid[j][i] == 1 && visited[i] == false){
25                visited[i] = true;
26                q.push(i);
27            }
28        }
29        }
30        
31    }
32};