// Last updated: 2/27/2026, 8:09:04 PM
1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int rows = mat.size(), cols = mat[0].size();
5        queue<pair<int, int>> q;
6        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
7        for(int i = 0; i < rows; i++){
8            for(int j = 0; j < cols; j++){
9                if(mat[i][j] == 0){
10                    dist[i][j] = 0;
11                    q.push({i, j});
12                }
13            }
14        }
15        const int dx[4] = {0, 0, -1, 1};
16        const int dy[4] = {-1, 1, 0, 0};
17        while(!q.empty()){
18            auto [x, y] = q.front();
19            q.pop();
20            for(int i = 0 ; i < 4; i++){
21                int nx = x + dx[i];
22                int ny = y + dy[i];
23                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && mat[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1){
24                    dist[nx][ny] = dist[x][y] + 1;
25                    q.push({nx, ny});
26                }
27            }
28        }
29        return dist;
30    }
31};