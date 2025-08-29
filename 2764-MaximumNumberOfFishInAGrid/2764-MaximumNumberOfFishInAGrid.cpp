// Last updated: 8/29/2025, 9:48:02 PM
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 0 && visited[i][j] == 0){
                    bfs(grid, visited, i, j, ans, rows, cols);
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int &ans, int rows, int cols){
        int count = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        int xOffset[4] = {0,0,1,-1};
        int yOffset[4] = {1, -1, 0, 0};
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            count += grid[p.first][p.second];
            for(int i = 0 ; i < 4; i++){
                int newX = p.first + xOffset[i];
                int newY = p.second + yOffset[i];
                cout << newX << " " << newY << " " << rows << " " << cols << " " << endl;
                if(newX >= 0 && newY >= 0 && newX < rows && newY < cols && visited[newX][newY] == 0 && grid[newX][newY] != 0){
                    visited[newX][newY] = 1;
                    q.push(make_pair(newX, newY));
                }
            }
        }
        ans = max(ans, count);
        // cout << ans << endl;
    }
};