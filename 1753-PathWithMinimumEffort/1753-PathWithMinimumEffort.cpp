// Last updated: 8/29/2025, 9:48:57 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;
        // {effort, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int xOffset[4] = {0, 0, 1, -1};
        int yOffset[4] = {1, -1, 0, 0};
        while(pq.empty() == false){
            auto [e, x, y] = pq.top(); pq.pop();
            if(e > effort[x][y])
                continue;
            // traverse all 4 directions 
            for(int i = 0; i < 4; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                if(newX >= 0 && newY >= 0 && newX < rows && newY < cols){
                    if(max(e, abs(heights[newX][newY] - heights[x][y])) < effort[newX][newY]){
                        effort[newX][newY] = max(e, abs(heights[newX][newY] - heights[x][y]));
                        pq.push({effort[newX][newY], newX, newY});
                    }
                }
            }
        }
        return effort[rows-1][cols-1];
    }
};