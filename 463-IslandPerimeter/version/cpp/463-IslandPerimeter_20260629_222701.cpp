// Last updated: 6/29/2026, 10:27:01 PM
1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        // we will do a bfs search 
5
6        // whenever a land's edge is water we will add to the perimeter 
7
8        int rows = grid.size(), cols = grid[0].size();
9
10        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
11
12        for(int i = 0; i < rows; i++){
13            for(int j = 0; j < cols; j++){
14                if(grid[i][j] == 1){
15                    int perimeter = bfs(i, j, grid, visited); // we are guaranteed we have only 1 island 
16                    return perimeter; 
17                }
18            }
19        }
20
21        return -1;
22    }
23
24    int bfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited){
25        visited[x][y] = true;
26        int dx[4] = {0, 0, -1, 1};
27        int dy[4] = {1, -1, 0, 0};
28        int rows = grid.size(), cols = grid[0].size();
29        queue<pair<int, int>> q;
30        int perimeter = 0;
31        q.push({x, y});
32        while(!q.empty()){
33            auto [currX, currY] = q.front();
34            q.pop();
35            int newX, newY;
36            for(int i = 0; i < 4; i++){
37                newX = currX + dx[i];
38                newY = currY + dy[i];
39                // check if the new coordinates are valid and land 
40                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1 && visited[newX][newY] == false){
41                    visited[newX][newY] = true;
42                    q.push({newX, newY});
43                } else if(newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] == 0){
44                    perimeter++;
45                }
46            }
47        }
48        return perimeter;
49    }
50
51
52};