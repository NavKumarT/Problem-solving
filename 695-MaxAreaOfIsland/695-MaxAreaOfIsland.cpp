// Last updated: 8/29/2025, 9:50:19 PM
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    bfs(grid, visited, rows, cols, i, j, maxArea);
                }
            }
        }
        return maxArea;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int &rows, int &cols, int &i, int &j, int &maxArea){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        int count = 1;
        maxArea = max(maxArea, count);
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        while(q.empty() == false){
            pair<int, int> p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = p.first + x[i];
                int newY = p.second + y[i];
                if(newX < rows && newX >= 0 && newY < cols && newY >= 0 && visited[newX][newY] == false && grid[newX][newY] == 1){
                        visited[newX][newY] = 1;
                        q.push(make_pair(newX, newY));
                        count++;
                        maxArea = max(maxArea, count);
                } 
            }
        }  
    }
};