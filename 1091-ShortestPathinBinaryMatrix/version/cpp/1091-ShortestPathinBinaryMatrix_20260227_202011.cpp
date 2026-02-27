// Last updated: 2/27/2026, 8:20:11 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int rows = grid.size(), cols = grid[0].size();
5        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
6        queue<pair<int, int>> q;
7        if(grid[0][0] == 0){
8            q.push({0, 0});
9            dist[0][0] = 1;
10        }
11        const int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
12        const int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
13        while(!q.empty()){
14            auto [x, y] = q.front();
15            q.pop();
16            for(int i = 0; i < 8; i++){
17                int nx = x + dx[i];
18                int ny = y + dy[i];
19                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1){
20                    dist[nx][ny] = dist[x][y] + 1;
21                    q.push({nx, ny});
22                }
23            }
24        }
25        return dist[rows-1][cols-1] == INT_MAX ? -1 : dist[rows-1][cols-1];
26    }
27};