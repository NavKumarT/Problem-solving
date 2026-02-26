// Last updated: 2/26/2026, 2:01:16 PM
1class Solution {
2public:
3    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
4        int rows = heights.size(), cols = heights[0].size();
5        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols, false));
6        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols, false));
7        for(int i = 0; i < cols; i++){
8            if(pacificVisited[0][i] == false){
9                bfs(0, i, pacificVisited, heights);
10            }
11        }
12        for(int i = 0; i < rows; i++){
13            if(pacificVisited[i][0] == false){
14                bfs(i, 0, pacificVisited, heights);
15            }
16        }
17        for(int i = 0; i < cols; i++){
18            if(atlanticVisited[rows-1][i] == false){
19                bfs(rows-1, i, atlanticVisited, heights);
20            }
21        }
22        for(int i = 0; i < rows; i++){
23            if(atlanticVisited[i][cols-1] == false){
24                bfs(i, cols-1, atlanticVisited, heights);
25            }
26        }
27        vector<vector<int>> n;
28        for(int i = 0 ; i < rows; i++){
29            for(int j = 0; j < cols; j++){
30                if(atlanticVisited[i][j] && pacificVisited[i][j]){
31                    n.push_back({i, j});
32                }
33            }
34        }
35        return n;
36    }
37
38    void bfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &grid){
39        int rows = grid.size(), cols = grid[0].size();
40
41        const int dx[4] = {0, 0, 1, -1};
42        const int dy[4] = {1, -1, 0, 0};
43        visited[x][y] = true;
44        queue<pair<int, int>> q;
45        q.push({x, y});
46        while(!q.empty()){
47            auto [x, y] = q.front();
48            q.pop();
49            for(int i = 0 ; i < 4; i++){
50                int nx = x + dx[i];
51                int ny = y + dy[i];
52                if(nx < rows && nx >= 0 && ny < cols && ny >= 0 && visited[nx][ny] == false && grid[nx][ny] >= grid[x][y]){
53                    visited[nx][ny] = true;
54                    q.push({nx, ny});
55                }
56            }
57        }
58    }
59};