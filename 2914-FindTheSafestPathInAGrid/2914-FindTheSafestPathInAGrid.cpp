// Last updated: 8/29/2025, 9:47:55 PM
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // find all the thieves 
        queue<pair<int, int>> q;
                int xOffset[4] = {0, 0, 1, -1};
        int yOffset[4] = {1, -1, 0, 0};
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dist (rows, vector<int>(cols, -1));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while(q.empty() == false){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                if(newX < rows && newX >= 0 && newY < cols && newY >= 0 && dist[newX][newY] == -1){
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        vector<vector<int>> max_safeness(rows, vector<int> (cols, -1));
        priority_queue<tuple<int, int, int>> pq;
        pq.push({dist[0][0], 0, 0});
        // max_safeness[0][0] = dist[0][0];

        while(pq.empty() == false){
            auto [safeness, x, y] = pq.top(); pq.pop();
            if(safeness < max_safeness[x][y])
                continue;
            for(int i = 0; i < 4; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                if(newX < rows && newX >= 0 && newY < cols && newY >= 0){
                    if(min(safeness, dist[newX][newY]) > max_safeness[newX][newY]){
                        max_safeness[newX][newY] = min(safeness, dist[newX][newY]);
                        pq.push({max_safeness[newX][newY], newX, newY});
                    }
                }
            }
        }
        return max_safeness[rows-1][cols-1] == -1 ? 0 : max_safeness[rows-1][cols-1];
    }
};