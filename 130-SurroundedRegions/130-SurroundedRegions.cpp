// Last updated: 8/29/2025, 9:52:18 PM
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O')
                    bfs(board, visited, i, j, rows, cols);
            }
        }
    }

    void bfs(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, int rows, int cols){
        queue<pair<int, int>> q;
        vector<pair<int, int>> c;
        c.push_back(make_pair(i, j));
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        bool isValid = true;
        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        while(q.empty() == false){
            pair<int, int> p = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int newX = p.first + x[i]; 
                int newY = p.second + y[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && board[newX][newY] == 'O' && visited[newX][newY] == 0){
                    visited[newX][newY] = 1;
                    q.push(make_pair(newX, newY));
                    c.push_back(make_pair(newX, newY));
                    if((newX == rows || newX == 0 || newY == 0 || newY == cols) && board[newX][newY] == 'O'){
                        isValid = false;
                    }
                } else if(newX >= rows || newX < 0 || newY >= cols || newY < 0){
                    isValid = false;
                }
            }
        }
        if(isValid){
            for(pair<int, int> p : c)
                board[p.first][p.second] = 'X';
        }
    }

};