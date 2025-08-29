// Last updated: 8/29/2025, 9:49:29 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<int>> visited(grid.size(), vector<int>(grid.size(), 0));
        visited[0][0] = 1;
        if(grid[0][0] == 0)
            bfs(grid, visited, 0, 0, ans, 1);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }

    void bfs(vector<vector<int>> grid, vector<vector<int>> &visited, int x, int y, int &ans, int count){
        visited[x][y] = 1;
        int xOffset[8] = {0,0,1,-1,1,-1, 1,-1};
        int yOffset[8] = {1,-1,0,0, 1, -1, -1, 1};
        queue<pair<int, pair<int, int>>> q;
        q.push(make_pair(count, make_pair(x, y)));
        while(q.empty() == false){
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int parentCount = p.first;
            x = p.second.first;
            y = p.second.second;
            if(x == grid.size()-1 && y == grid.size()-1)
                ans = min(ans, parentCount);
            for(int i = 0; i <8; i++){
                int newX = x + xOffset[i];
                int newY = y + yOffset[i];
                // cout << newX << " " << newY << endl;
                if(isLegalCell(newX, newY, grid.size()) && grid[newX][newY] == 0 && visited[newX][newY] == 0)   {
                    visited[newX][newY] = 1;
                    // dfs(grid, visited, newX, newY, ans, count + 1);
                    q.push(make_pair(parentCount+1, make_pair(newX, newY)));
                }
            }
        }
    }

    bool isLegalCell(int x, int y, int n){
        if(x >= 0 && y >= 0 && x < n && y < n)
            return true;
        else 
            return false;
    }

};