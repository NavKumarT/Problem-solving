// Last updated: 3/23/2025, 12:37:36 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        int xOffset[4] = {0,0,-1,1};
        int yOffset[4] = {1,-1,0,0};

        while(pq.empty() == false){
            auto [currEffort, x, y] = pq.top(); pq.pop();
            if(currEffort > effort[x][y])
                continue;
            for(int i = 0; i < 4; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols){
                    int newEffort = max(currEffort, abs(heights[x][y] - heights[newX][newY]));
                    if(newEffort < effort[newX][newY]){
                        effort[newX][newY] = newEffort;
                        pq.emplace(newEffort, newX, newY);
                    }
                }
            }
        } 
        return effort[rows-1][cols-1];
    }
};