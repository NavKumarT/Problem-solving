// Last updated: 8/29/2025, 9:50:42 PM
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // write a bfs algorithm that adds to a count of sides not land
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int perimeter = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    bfs(grid, visited, rows, cols, i, j, perimeter);
                }
            }
        }
        return perimeter;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int rows, int cols, int i, int j, int &perimeter){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        while(q.empty() == false){
            pair<int, int> p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = p.first + x[i];
                int newY = p.second + y[i];
                if(newX < rows && newX >= 0 && newY < cols && newY >= 0 && visited[newX][newY] == 0 && grid[newX][newY] == 1){
                        visited[newX][newY] = 1;
                        q.push(make_pair(newX, newY));
                } else if(newX >= rows || newX < 0 || newY >= cols || newY < 0 || (newX < rows && newX >= 0 && newY < cols && newY >= 0 && grid[newX][newY] == 0)){
                    perimeter++;
                }
            }
        }  
    }
};