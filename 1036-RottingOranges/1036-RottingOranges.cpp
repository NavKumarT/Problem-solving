// Last updated: 8/29/2025, 9:49:39 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q; // contains rotten oranges, to be used by bfs 
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));   
            }
        }
        int count = -1;
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        while(q.empty() == false){
            count++;
            int size = q.size();
            for(int j = 0; j < size; j++){
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int newX = p.first + x[i];
                    int newY = p.second + y[i];
                    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1){
                        q.push(make_pair(newX, newY));
                        grid[newX][newY] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 1)
                    return -1;
        return count <= 0 ? 0 : count;
    }
};