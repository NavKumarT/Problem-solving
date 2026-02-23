// Last updated: 2/23/2026, 7:49:41 PM
1class Solution {
2private:
3    vector<vector<int>> flipVertices;
4
5public:
6    void solve(vector<vector<char>>& board) {
7        int rows = board.size(), cols = board[0].size();
8        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
9        for (int i = 0; i < rows; i++) {
10            for (int j = 0; j < cols; j++) {
11                if ( (i == 0|| j ==0 || i == rows-1 || j == cols-1) && board[i][j] == 'O' && visited[i][j] == false) {
12                    visited[i][j] = true;
13                    bfs(i, j, board, visited, false);
14                }
15            }
16        }
17        for (int i = 0; i < rows; i++) {
18            for (int j = 0; j < cols; j++) {
19                if(board[i][j] == '#')
20                    board[i][j] = 'O';
21                else if(board[i][j] == 'O')
22                    board[i][j] = 'X';
23            }
24        }
25    }
26
27    void bfs(int i, int j, vector<vector<char>>& board,
28             vector<vector<bool>>& visited, bool changeVertex) {
29        int rows = board.size(), cols = board[0].size();
30        queue<pair<int, int>> q;
31        q.push({i, j});
32        visited[i][j] = true;
33        board[i][j] = '#';
34        while (q.empty() == false) {
35            auto [x, y] = q.front();
36            board[x][y] = '#';
37            q.pop();
38            int xOffset[4] = {0, 0, 1, -1};
39            int yOffset[4] = {1, -1, 0, 0};
40            for (int i = 0; i < 4; i++) {
41                int newX = x + xOffset[i];
42                int newY = y + yOffset[i];
43                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
44                    visited[newX][newY] == false && board[newX][newY] == 'O') {
45                    visited[newX][newY] = true;
46                    q.push({newX, newY});
47                }
48            }
49        }
50    }
51};