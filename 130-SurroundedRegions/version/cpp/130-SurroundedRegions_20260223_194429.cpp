// Last updated: 2/23/2026, 7:44:29 PM
1class Solution {
2private:
3    vector<vector<int>> flipVertices;
4
5public:
6    void solve(vector<vector<char>>& board) {
7        int rows = board.size(), cols = board[0].size();
8        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
9        for (int i = 1; i < rows; i++) {
10            for (int j = 1; j < cols; j++) {
11                if (board[i][j] == 'O' && visited[i][j] == false) {
12                    visited[i][j] = true;
13                    bfs(i, j, board, visited, false);
14                }
15            }
16        }
17        visited.assign(rows, vector<bool>(cols, false));
18        for (int i = 0; i < flipVertices.size(); i++) {
19            cout << i << " " <<flipVertices.size() << endl;
20            vector<int> v = flipVertices[i];
21            bfs(v[0], v[1], board, visited, true);
22        }
23    }
24
25    void bfs(int i, int j, vector<vector<char>>& board,
26             vector<vector<bool>>& visited, bool changeVertex) {
27        int rows = board.size(), cols = board[0].size();
28        queue<pair<int, int>> q;
29        q.push({i, j});
30        visited[i][j] = true;
31        bool flipgroup = false;
32        while (q.empty() == false) {
33            auto [x, y] = q.front();
34            if (isEdge(rows, cols, x, y)) {
35                flipgroup = true;
36            }
37            if (changeVertex)
38                board[x][y] = 'X';
39            q.pop();
40            int xOffset[4] = {0, 0, 1, -1};
41            int yOffset[4] = {1, -1, 0, 0};
42            for (int i = 0; i < 4; i++) {
43                int newX = x + xOffset[i];
44                int newY = y + yOffset[i];
45                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
46                    visited[newX][newY] == false && board[newX][newY] == 'O') {
47                    visited[newX][newY] = true;
48                    q.push({newX, newY});
49                }
50            }
51        }
52        if (!flipgroup && !changeVertex)
53            flipVertices.push_back({i, j});
54    }
55
56    bool isEdge(int rows, int cols, int x, int y) {
57        return x == rows - 1 || y == cols - 1 || x == 0 || y == 0;
58    }
59};