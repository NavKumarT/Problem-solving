// Last updated: 8/29/2025, 9:50:33 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int xOffset[4] = {0, 0, 1, -1};
        int yOffset[4] = {1, -1, 0, 0};
        while(q.empty() == false){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && dist[newX][newY] == -1){
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return dist;
    }
};