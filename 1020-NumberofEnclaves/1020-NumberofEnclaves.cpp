class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!(i == 0 || i == m || j == 0 || j == n) && grid[i][j] == 1 && visited[i][j] == 0)
                    bfs(visited, grid, i, j, count);
            }
        }
        return count;
    }

     void bfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int x, int y, int &count){
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        int xOffset[4] = {0,0,1,-1};
        int yOffset[4] = {1,-1,0,0};
        bool isBorder = false;
        int ans = 0;
        while(q.empty() == false){
            pair<int, int> p = q.front();
            q.pop();
            ans++;
            if(p.first == 0 || p.first == grid.size()-1 || p.second == 0 || p.second == grid[0].size()-1){
                isBorder = true;
            }
            for(int i = 0; i < 4; i++){
                int newX = p.first + xOffset[i];
                int newY = p.second + yOffset[i];
                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && visited[newX][newY] == 0 && grid[newX][newY] == 1){
                    visited[newX][newY] = 1;
                    q.push(make_pair(newX, newY));
                }
            }
        }
        if(isBorder == false)
            count += ans;
    }
};