// Last updated: 2/23/2026, 8:52:14 PM
1class Solution {
2public:
3    int numIslands(vector<vector<char>>& grid) {
4        int count = 0, rows = grid.size(), cols = grid[0].size();
5        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
6        for(int i = 0; i < rows; i++){
7            for(int j = 0; j < cols; j++){
8                if(grid[i][j] == '1' && visited[i][j] == false){
9                    bfs(i, j, grid, visited);
10                    count++;
11                }
12            }
13        }
14        return count;
15    }
16
17    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
18        int rows = grid.size(), cols = grid[0].size();
19        queue<pair<int, int>> q;
20        q.push({i, j});
21        visited[i][j] = true;
22        while(q.empty() == false){
23            auto [x, y] = q.front();
24            q.pop();
25            int xOffset[4] = {0, 0, 1, -1};
26            int yOffset[4] = {1, -1, 0, 0};
27            for(int i = 0; i < 4; i++){
28                int newX = x + xOffset[i];
29                int newY = y + yOffset[i];
30                if(newX < rows && newX >= 0 && newY < cols && newY >= 0 && grid[newX][newY] == '1' && visited[newX][newY] == false){
31                    visited[newX][newY] = true;
32                    q.push({newX, newY});
33                }
34            }
35        }
36    }
37};