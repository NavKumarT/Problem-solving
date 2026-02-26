// Last updated: 2/27/2026, 12:14:19 AM
1class Solution {
2public:
3    int numEnclaves(vector<vector<int>>& grid) {
4        int rows = grid.size(), cols = grid[0].size();
5        for(int i = 0; i < cols; i++){
6            bfs(0, i, grid);
7        }
8        for(int i = 0; i < cols; i++){
9            bfs(rows-1, i, grid);
10        }
11        for(int i = 0; i < rows; i++){
12            bfs(i, 0, grid);
13        }
14        for(int i = 0 ; i < rows; i++){
15            bfs(i, cols-1, grid);
16        }
17        int count = 0;
18        for(int i = 0; i < rows; i++){
19            for(int j = 0; j < cols; j++){
20                if(grid[i][j] == 1)
21                    count++;
22            }
23        }
24        return count;
25    }
26
27    void bfs(int x, int y, vector<vector<int>> &grid){
28        int rows = grid.size(), cols = grid[0].size();
29        queue<pair<int, int>> q;
30        if(grid[x][y] == 0)
31            return;
32        q.push({x, y});
33        const int dx[4] = {0, 0, 1, -1};
34        const int dy[4] = {1, -1, 0, 0};
35        while(!q.empty()){
36            auto [x, y] = q.front();
37            q.pop();
38            grid[x][y] = 0;
39            for(int i = 0 ; i < 4; i++){
40                int nx = x + dx[i];
41                int ny = y + dy[i];
42                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1){
43                    grid[nx][ny] = 0;
44                    q.push({nx, ny});
45                }
46            }
47        }
48    }
49};