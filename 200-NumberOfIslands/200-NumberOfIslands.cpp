// Last updated: 8/29/2025, 9:51:28 PM
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // write a bfs algorithm 
        int rows = grid.size(), cols = grid[0].size();
        int count = 0; // count of islands 
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count++;
                    bfs(grid, visited, i, j, rows, cols);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int currentX, int currentY, int rows, int cols){
        queue<pair<int, int>> qq;
        qq.push(make_pair(currentX, currentY));
        visited[currentX][currentY] = true;
        int xOffset[4] = {0, 0, 1, -1};
        int yOffset[4] = {1, -1, 0, 0};
        while(qq.empty() == false){
            pair<int, int> pp = qq.front();
            qq.pop();
            for(int i = 0; i < 4; i++){
                int newX = pp.first + xOffset[i];
                int newY = pp.second + yOffset[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1' && visited[newX][newY] == false){
                    qq.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
    }

};